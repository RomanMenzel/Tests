# -*- coding: utf-8 -*-

dic = {
	'james':{"nummer":"9859393", "hobby":"programmieren"},    # {
	'chris':{"nummer":"636463", "hobby":"fußball spielen"},   # {  Die Nummern sind nur Beispiel Nummern
 	'richard':{"nummer":"8723646", "hobby":"musik hören"}     # {
}

input1 = raw_input("Welchen Kunden? ")

if input1 in dic:	
	print "=> {0}".format(input1)
	input2 = raw_input("Welche Information? ")
	if input2 in dic[input1]:
		print dic[input1][input2]
	else:
		print "Die Infomation zum Kunden existiert nicht"
		
else:
	print "Der von dir eingegebene Kunde existiert nicht!"

