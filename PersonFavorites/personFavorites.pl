#! usr/bin/perl 
use strict;

my $person = undef;

my %ryan_favorites = ("food"=>["jambalaya"], "basketball team"=>["spartans", "pistons"]);
my %matt_favorites = ("food"=>["little debbie's"], "basketball team"=>["wolverines"]);
my %people = (
	"ryan"=>\%ryan_favorites,
	"matt"=>\%matt_favorites,
	"logan"=>{"food"=>["pizza"], "basketball team"=>["lakers"]}
);

my @main_options = ("Add a person", "Delete a person", "Rename a person", "Select a person", "Print", "Exit");
my @person_selected_options = ("Add a property", "Delete a property", "Delete specific property", "Change a property", "Print", "Go back", "Exit");

sub printMenu {
	my ($current_person) = @_;
	my $option_number = 1;
	
	if ($current_person) {
		print "Currently working with $current_person\n";
		foreach my $person_option (@person_selected_options) {
			print "$option_number.\t$person_option\n";
			$option_number++;
		}
	}
	else {
		print "Main menu:\n";
		foreach my $main_option (@main_options) {
			print "$option_number.\t$main_option\n";
			$option_number++;
		}
	}
}

sub getAndProcessOption {
	my ($current_person) = @_;
	
	my $valid_option = 0;
	
	until ($valid_option) {
		print "Which option do you want? ";
		chomp (my $option = <>);
		
		#  Assume a valid option until we determine otherwise
		$valid_option = 1;
		
		if ($current_person) {
			if ($option eq "1") {
				addProperty($current_person);
			}
			elsif ($option eq "2") {
				deleteProperty($current_person);
			}
			elsif ($option eq "3") {
				deleteSpecificProperty($current_person);
			}
			elsif ($option eq "4") {
				changeProperty($current_person);
			}
			elsif ($option eq "5") {
				printPerson($current_person);
			}
			elsif ($option eq "6") {
				$current_person = undef;
			}
			elsif ($option eq "7") {
				endProgram();
			}
			else {
				print "Please enter a value between 1 and " . 
					 scalar @person_selected_options . "\n";
				$valid_option = 0;
			}	
		}
		else {
			if ($option eq "1") {
				$current_person = addPerson();
			}
			elsif ($option eq "2") {
				deletePerson();
			}
			elsif ($option eq "3") {
				renamePerson();
			}
			elsif ($option eq "4") {
				$current_person = selectPerson("select");
			}
			elsif ($option eq "5") {
				printPeople();
			}
			elsif ($option eq "6") {
				endProgram ();
			}
			else {
				print "Please enter a value between 1 and " . 
					 scalar @main_options . "\n";
				$valid_option = 0;
			}				
		}
	}
	
	return $current_person;
}

sub addProperty {
	my ($person) = @_;
	print "What property do you want to add for $person?\n";
	chomp (my $property = <STDIN>);
	print "What is ${person}'s favorite $property?\n";
	chomp (my $value = <STDIN>);
	my @array = split (",", $value);
	${$people{$person}}{$property} = \@array;
	print "Set property $property to $value for $person\n";
}

sub deleteProperty {
	my ($person) = @_;
	my $property = undef;
	
	printPropertiesForPerson ($person);
	if(keys %{$people{$person}}==0){
	return 0;
	}
	until (${$people{$person}}{$property}) {
		print "Enter the name of the property to delete: ";
		chomp ($property = <STDIN>);
		print "The property $property does not exist for $person\n"
			unless ${$people{$person}}{$property};
	}

	delete ${$people{$person}}{$property};
	
	print "The property $property for $person has been deleted\n";
}

sub deleteSpecificProperty {
 my ($person) = @_;
	my $property = undef;
	
	printPropertiesForPerson ($person);
	if(keys %{$people{$person}}==0){
	return 0;
	}
	until (${$people{$person}}{$property}) {
		print "Enter the name of the property to delete: ";
		chomp ($property = <STDIN>);
		print "The property $property does not exist for $person\n"
			unless ${$people{$person}}{$property};
	}

	delete ${$people{$person}}{$property}[$property];
	
	print "The property $property for $person has been deleted\n";
  
}
sub changeProperty {
	my ($person) = @_;
	my $property = undef;
	
	return unless printPropertiesForPerson ($person);
	
	until (${$people{$person}}{$property}) {
		print "Enter the property you want to change: ";
		chomp ($property = <STDIN>);
		print "The property $property does not exist for $person\n"
			unless (${$people{$person}}{$property});
	}
	
	print "Enter the new value for the property $property: ";
	chomp (my $value = <STDIN>);
	my @changedArray = split (",", $value);
	${$people{$person}}{$property} = \@changedArray;
	
	print "Set property $property to $value for $person\n";
	return $person;
}



sub addPerson {
	my $person = "";
	
	do {
		print "Enter the name of the person to add: ";
		chomp ($person = <>);
		print "$person already exists, try again!\n" 
			if ($people{$person});
	} while ($people{$person});
	$people{$person} = {};
	
	#  Leave this line as it stands
	return $person;
}


sub deletePerson {
	my $person = selectPerson ("delete");
	delete $people{$person};
}

sub renamePerson {
	my $person = selectPerson ("rename");
	my $new_name = $person;
	while ($people{$new_name}) {
		print "Enter a new name for $person: ";
		chomp ($new_name = <STDIN>);
		print "The name $new_name already exists.  Choose another please!\n"
			if $people{$new_name};
	}
	
	#  Complete the implementation of this method below this comment
	my %copyHash = %{$people{$person}};
	$people{$new_name} = \%copyHash;
	delete $people{$person};
	
	#  Leave this line as it stands
	print "Name changed from $person to $new_name\n";
}

sub selectPerson {
	my ($action) = @_;
	if(scalar keys %people == 0){
	print "There are no more people that I know. Please add a person!\n";
	return 0;
	}
	elsif(scalar keys %people ==1){
	print "Here is the 1 person I know :\n";
	}
	elsif(scalar keys %people > 1){
	print "Here are the " . scalar (keys %people) . " people I know:\n";
	}
	#  Print out the available names
	foreach $person (keys %people) {
		print "\t$person\n";
	}
	
	#  Read a name from standard input until a valid name is chosen
	until ($people{$person}) {
		print "Who do you want to $action?\n";
		chomp ($person = <>);
	} 
	
	return $person;
}

sub printPerson {
    my ($person) = @_;
	print "$person\n";
	print "\tFavorites: \n";
	if(keys %{$people{$person}} == 0 ){
	  print "There is no info on $person! Add some info!\n";
	}
	foreach my $element (keys %{$people{$person}}){
	  print "\t\t $element: @{$people{$person}{$element}}\n";
	}
}

sub printPropertiesForPerson {
	my ($person) = @_;
	if(keys %{$people{$person}}==0 | keys %{$people{$person}} eq undef){
	  print "\n$person does not have any info!\nPlease choose a different option.\n\n";
	  return 0;
	}
	print "Here are the properties for $person\n";
	foreach my $element (values %{$people{$person}}){
	  print "\t@$element\n";
	}
    return 1;
}

sub printPeople {
	foreach my $person (sort keys %people) {
		printPerson ($person);
	}
}

sub endProgram {
	print "Goodbye!\n";
	exit;
}

while (1) {
	printMenu($person);
	$person = getAndProcessOption ($person);
}
