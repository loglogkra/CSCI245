#! usr/bin/perl

#open the file but throw exception if it can't 
open(PROTEINFILE, 'NM_021964.fasta') or die "Could not open file";

#get header 1st line 
$header = <PROTEINFILE>;

#initialize empty array 
@array;
#put all lines below header into array
 while($protein = <PROTEINFILE>){ 
    chomp $protein; #chomp/get rid of new lines
    push @array, $protein; #add all lines without whitespace onto array 
    }

#create second array
@array2; 
foreach $line (@array){
     @base = split ("", "$line"); #split each line up on each char 
     push @array2, @base; #push each char into @array2 
     }

#Count each "G" or "C"
 $counter = 0; 
 foreach $letter (@array2){
      if($letter eq "C" || $letter eq "G"){  $counter++; } 
      }

#do math for final print statement 
$per = $counter/scalar @array2; $per = sprintf '%.2f%%', 100 * $per; #made percent with only 2 decimals to right..looks weird with more) 
print "The Percent GC is ".$counter." out of ".scalar @array2.": ".$per."%\n";