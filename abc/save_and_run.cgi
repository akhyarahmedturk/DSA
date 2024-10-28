#!/usr/bin/perl
use strict;
use warnings;

# Read the input from the form
my $buffer;
read(STDIN, $buffer, $ENV{'CONTENT_LENGTH'});

# Extract the code from the input (this will depend on how form data is sent)
my ($code) = $buffer =~ /code=(.*)/;

# URL decode the code (in case of special characters)
$code =~ tr/+/ /;
$code =~ s/%([0-9A-Fa-f]{2})/chr(hex($1))/eg;

# Save the code to a file (e.g., submitted_code.cpp)
my $file_path = "C:/xampp/cgi-bin/submitted_code.cpp";
open(my $fh, '>', $file_path) or die "Could not open file '$file_path' $!";
print $fh $code;
close $fh;

# Run the C++ program that will compile and check the submitted code
my $output = `g++ C:/xampp/cgi-bin/submitted_code.cpp -o C:/xampp/cgi-bin/output_program 2>&1`;

# Check the output from the compiler
if ($output eq '') {
    # Compilation successful, now run the output program
    my $run_output = `C:/xampp/cgi-bin/output_program`;

    # Print the success message
    print "Content-Type: text/html\n\n";
    print "<html><body><h1>Code compiled and executed successfully!</h1>";
    print "<p>Output: $run_output</p></body></html>";
} else {
    # Print the error message
    print "Content-Type: text/html\n\n";
    print "<html><body><h1>Compilation Error!</h1>";
    print "<pre>$output</pre></body></html>";
}
