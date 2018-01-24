!# usr/bin/perl -w 
 
die if(@ARGV <1); 
 
open (FILE, $ARGV[0]) or die; #should use file name instead of ARGV
 
#Grab 1st line since its not important
$header = <FILE>; 
 
#Why not chomp carriage return all at once..
 chomp (@lines = <FILE>); 
 
#initialize counter and hash
%aminoHash; $total; 
 
#split lines into letters and count 
foreach $amacid(@lines){ 
      @letters=split("",$amacid);
         foreach $letter(@letters){ 
               $aminoHash{$letter}++;   $total++;   
               }
        } 
 
print "Number of occurrences for each Amino Acid: \n"; 
 
#sort the keys according to ASCII and print to return key/value 
foreach $entry(sort keys %aminoHash){ 
     print "$entry $aminoHash{$entry}\n"; 
     } 
 
print "\nNumber of different amino acids: ". scalar keys %aminoHash;
print "\n"; print "No occurrences of E, G or W \n\n"; 
 
print "Sorted occurrences of Amino Acids (Greatest to least)\n"; 
foreach $value(sort { $aminoHash{$b} <=> $aminoHash{$a} } keys %aminoHash) 
{    print "$value $aminoHash{$value}\n"; }