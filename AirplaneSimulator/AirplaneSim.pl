#! usr/bin/perl  use strict; 
 
#why not use the already made shuffle method
use List::Util qw(shuffle); 
 
#Continue with program if user enters correct amount of args
if(@ARGV==2){ 
    print "\n\tWelcome to the airplane game!\n\n";  
	
#assign args         
my $numberOfSeats = ($ARGV[0]);  
my $iterations = ($ARGV[1]);    
my $final;         

#use $iterations here to call &loadPlane  
for(my $i=0; $i < $iterations; $i++){  
 &loadPlane;  }    
 
#main subroutine that loads the plane  
sub loadPlane{         
#randomly assign seats to all passengers        
 my @initialSeatAssignments = shuffle(1..$numberOfSeats);
 print "The initial Seat Assignments were:   @initialSeatAssignments\n";     
 
 #All seats are empty here  
 my @seatsTaken;   
 $#seatsTaken = $numberOfSeats -1;    
 
 #let the first passenger pick a random seat         
 my $first = int(rand($numberOfSeats));   
 @seatsTaken[$first] = 1; 
 
  #loop through passengers and see if their seat is taken...   
  #If it is then assign them a random seat...   
  for(my $int = 2; $int <= $numberOfSeats; $int++){ 
	if($seatsTaken[$initialSeatAssignments[$int-1]]==0){
		if($int == $numberOfSeats){ 
			$final++;     
			}  
  $seatsTaken[$initialSeatAssignments[$int-1]] = $int;   
  }    
  else{       
  $first = int(rand($numberOfSeats)) + 1 ;  
  while(!$seatsTaken[$first] == 0){     
  $first = int(rand($numberOfSeats)) + 1 ;   
  }     $seatsTaken[$first] = $int;  
  }  
  } 
  print "Here is after the plane was was loaded: @seatsTaken\n\n";  }  print "\n"; 
 
 
my $percent = (($final/$iterations) * 100); 
print "The last passenger got their seat $percent percent of the time!\n"; } 

else{
 die "You need to specify how many seats are on the plane and how many iterations! $!\n"; }
