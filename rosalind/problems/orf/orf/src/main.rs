#![cfg_attr(
    debug_assertions,
    allow(dead_code, unused_imports, unused_variables, unused_mut)
)]
use std::cmp::{max, min};
use std::collections::{BTreeMap, BTreeSet, HashMap, HashSet};
use std::io::{stdin, stdout, BufReader, BufWriter, Result, Write};
const BITS: usize = 19;

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}

impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> Option<T> {
        let mut input = String::new();
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse::<T>().ok();
            }
            if self.buffer.len() > 0 {
                continue;
            } else {
                input.clear();
            }
            stdin()
                .read_line(&mut input)
                .ok()
                .expect("Failed to read line");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
            if self.buffer.len() == 0 {
                return None;
            }
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let mut genes = HashMap::<String, String>::new();
    let mut gene = String::new();
    while let Some(line) = scan.next::<String>() {
        if line.starts_with(">") {
            gene = line.get(1..).expect("").to_string();
            genes.insert(gene.clone(), String::new());
        } else {
            if let Some(k) = genes.get_mut(&gene) {
                *k += &line;
            }
        }
    }

    for mut gene in &genes {
        let mut prots = HashSet::<String>::new();

        for j in 0..2 {
            let mut g = gene.1.to_string();
            if j % 2 == 1 {
                g = reverse_complement(gene.1.to_string())
            }
            for i in 0..3 {
                let mut s = g
                    .get(i..)
                    .expect("Failed to get substring")
                    .split("")
                    .filter(|c| !c.is_empty())
                    .collect::<Vec<_>>()
                    .into_iter();

                println!("{}:{} {:?}", j, i, &s.clone().collect::<String>());
                let mut prot = String::new();

                while !s.as_slice().is_empty() {
                    let m: String = s.by_ref().take(3).collect();
                    if m.len() != 3 {
                        continue;
                    }
                    let aa = &dna_to_aa(m);
                    // println!("    {:?}\t{:?}", s.clone().collect::<String>(), &aa);
                    // println!("{:?} : {:?}", prot, aa);
                    if prot.is_empty() && aa != "M" {
                        continue;
                    }
                    if aa == "STOP" {
                        prots.insert(prot);
                        prot = String::new();
                    } else {
                        prot += aa;
                    }
                }
            }
        }

        println!("{:?}", prots);
    }

    // println!("{:?}", genes);
}

fn dna_to_aa(seq: String) -> String {
    let m: HashMap<&str, &str> = [
        ("AAA", "K"),
        ("AAC", "N"),
        ("AAG", "K"),
        ("AAT", "N"),
        ("ACA", "T"),
        ("ACC", "T"),
        ("ACG", "T"),
        ("ACT", "T"),
        ("AGA", "R"),
        ("AGC", "S"),
        ("AGG", "R"),
        ("AGT", "S"),
        ("ATA", "I"),
        ("ATC", "I"),
        ("ATG", "M"),
        ("ATT", "I"),
        ("CAA", "Q"),
        ("CAC", "H"),
        ("CAG", "Q"),
        ("CAT", "H"),
        ("CCA", "P"),
        ("CCC", "P"),
        ("CCG", "P"),
        ("CCT", "P"),
        ("CGA", "R"),
        ("CGC", "R"),
        ("CGG", "R"),
        ("CGT", "R"),
        ("CTA", "L"),
        ("CTC", "L"),
        ("CTG", "L"),
        ("CTT", "L"),
        ("GAA", "E"),
        ("GAC", "D"),
        ("GAG", "E"),
        ("GAT", "D"),
        ("GCA", "A"),
        ("GCC", "A"),
        ("GCG", "A"),
        ("GCT", "A"),
        ("GGA", "G"),
        ("GGC", "G"),
        ("GGG", "G"),
        ("GGT", "G"),
        ("GTA", "V"),
        ("GTC", "V"),
        ("GTG", "V"),
        ("GTT", "V"),
        ("TAA", "STOP"),
        ("TAC", "Y"),
        ("TAG", "STOP"),
        ("TAT", "Y"),
        ("TCA", "S"),
        ("TCC", "S"),
        ("TCG", "S"),
        ("TCT", "S"),
        ("TGA", "STOP"),
        ("TGC", "C"),
        ("TGG", "W"),
        ("TGT", "C"),
        ("TTA", "L"),
        ("TTC", "F"),
        ("TTG", "L"),
        ("TTT", "F"),
    ]
    .iter()
    .cloned()
    .collect();

    if let Some(aa) = m.get(seq.as_str()) {
        return aa.to_string();
    } else {
        panic!("There is no AminoAcid for this codon: {:?}", seq);
    }
}

fn reverse_complement(seq: String) -> String {
    let new_seq = seq.chars().map(|c| {
        let x = match c {
            'A' => 'T',
            'C' => 'G',
            'G' => 'C',
            'T' => 'A',
            _ => 'X',
        };
        x
    }).rev().collect::<String>();
    return new_seq;
}
