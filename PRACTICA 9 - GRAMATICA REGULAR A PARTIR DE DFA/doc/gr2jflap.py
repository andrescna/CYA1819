#!/usr/bin/env python

import sys

if len(sys.argv) != 2:
	print "\n\nfile.gr conversor de formato CyA a formato JFLAP\n"
	print "Usage sys.argv[0] file.gr > file-JFLAP.jff\n"
	exit(1)

with open(sys.argv[1]) as f:
    content = f.readlines()
# you may also want to remove whitespace characters like `\n` at the end of each line
content = [x.strip() for x in content] 
# remove spaces
content = [x.replace(" ","") for x in content] 

# delete first 4 lines
content = content[4:]

# split in productions
rules = [x.split("->") for x in content] 

# Header
print "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?><!--Created with JFLAP 6.4.-->"
print "<structure>"
print " <type>grammar</type>"
print "	<!--The list of productions.-->"

# Productions
for r in rules:
  prods = r[1].split("|")
  for p in prods:
    print " <production>"
    print "   <left>" + r[0] +"</left>"
    if p is '~': 
      print "   <right/>"
    else:
      print "   <right>" + p + "</right>"
    print " </production>"
print "</structure>"



