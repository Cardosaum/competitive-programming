#!/usr/bin/env python3
from pprint import pprint
from sys import stdin

fasta = [str(x.strip()) for x in stdin.read().strip().split()]

table = {
    "AAA": "K",
    "AAC": "N",
    "AAG": "K",
    "AAT": "N",
    "ACA": "T",
    "ACC": "T",
    "ACG": "T",
    "ACT": "T",
    "AGA": "R",
    "AGC": "S",
    "AGG": "R",
    "AGT": "S",
    "ATA": "I",
    "ATC": "I",
    "ATG": "M",
    "ATT": "I",
    "CAA": "Q",
    "CAC": "H",
    "CAG": "Q",
    "CAT": "H",
    "CCA": "P",
    "CCC": "P",
    "CCG": "P",
    "CCT": "P",
    "CGA": "R",
    "CGC": "R",
    "CGG": "R",
    "CGT": "R",
    "CTA": "L",
    "CTC": "L",
    "CTG": "L",
    "CTT": "L",
    "GAA": "E",
    "GAC": "D",
    "GAG": "E",
    "GAT": "D",
    "GCA": "A",
    "GCC": "A",
    "GCG": "A",
    "GCT": "A",
    "GGA": "G",
    "GGC": "G",
    "GGG": "G",
    "GGT": "G",
    "GTA": "V",
    "GTC": "V",
    "GTG": "V",
    "GTT": "V",
    "TAA": "STOP",
    "TAC": "Y",
    "TAG": "STOP",
    "TAT": "Y",
    "TCA": "S",
    "TCC": "S",
    "TCG": "S",
    "TCT": "S",
    "TGA": "STOP",
    "TGC": "C",
    "TGG": "W",
    "TGT": "C",
    "TTA": "L",
    "TTC": "F",
    "TTG": "L",
    "TTT": "F",
}


def translate(seq):
    prots = set()
    for j in range(3):
        prot = ""
        # print(j)
        for i in zip(seq[j + 0 :: 3], seq[j + 1 :: 3], seq[j + 2 :: 3]):
            i = "".join(i)
            if len(i) % 3 != 0:
                continue
            c = table[i]
            # print(f"{i}:{c};{prot}\t{prots}")
            if prot == "" and c != "M":
                continue
            if c == "STOP":
                prots.add(prot)
                prot = ""
            else:
                prot += c
    return prots


def reverse_complement(seq):
    # print("\n\nREVERSE\n\n")
    s = ""
    for i in seq:
        if i == "A":
            s += "T"
        elif i == "G":
            s += "C"
        elif i == "C":
            s += "G"
        elif i == "T":
            s += "A"
    return s[::-1]


genes = {}
gene = ""
for l in fasta:
    if l.startswith(">"):
        gene = l[1:]
        genes.setdefault(gene, "")
    else:
        genes[gene] += l.strip()

prots = set()
for k, v in genes.items():
    # print(f"{k}:{v}")
    prots = translate(v).union(translate(reverse_complement(v)))

new_prots = set()
for prot in sorted(prots):
    p = prot
    while p.find("M") != -1 and len(p) > 1:
        p = p[p.find("M") + 1 :]
        new_prots.add("M" + p)

prots |= new_prots
[print(prot) for prot in sorted(prots)]
