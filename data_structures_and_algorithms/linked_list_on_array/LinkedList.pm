package LinkedList;

use Moose;

has size => (
		is => 'rw',
		isa => 'Int',
		default => 0
	);

has data => (
		is => 'rw',
		isa => 'ArrayRef',
		default => sub { [] }
 	);

has next => (
		is => 'rw',
		isa => 'ArrayRef',
		default => sub {
				my $self = shift;

				my $arr = [];
				for(my $i = 0;$i < $self->{size} - 1;$i++) {
					push @$arr, $i + 1;
				}
				push @$arr, -1;

				return $arr;
			}
	);

has first_empty => (
		is => 'rw',
		isa => 'Int',
		default => 0
	);

has head => (
		is => 'rw',
		isa => 'Int',
		default => -1
	);

sub _resize {
	my $self = shift;

	my $new_size = 2 * $self->{size} + 1;
	for(my $i = $self->{size}+1;$i < $new_size - 1;$i++) {
		push @{ $self->{next} }, $i + 1;
	}
	push @{ $self->{next} }, -1;
	$self->{first_empty} = $self->{size} + 1;
	$self->{size} = $new_size;
}

sub push_front {
	my ($self, $value) = @_;

	$self->_resize()
		if ($self->{first_empty} == -1);

	my $new_pos = $self->{first_empty};
	$self->{first_empty} = $self->{next}->[ $new_pos ];
	$self->{data}->[ $new_pos ] = $value;
	$self->{next}->[ $new_pos ] = $self->{head};
	$self->{head} = $new_pos;
}

sub push_back {
	my ($self, $value) = @_;

	$self->_resize()
		if ($self->{first_empty} == -1);

	if ($self->{head} == -1) {
		$self->push_front($value);
		return;
	}

	my $pos = $self->{head};

	while ($self->next->[ $pos ] != -1) {
		$pos = $self->{next}->[ $pos ];
	}

	my $new_pos = $self->{first_empty};

	$self->{data}->[ $new_pos ] = $value;
	$self->{first_empty} = $self->{next}->[ $new_pos ];

	$self->{next}->[ $pos ] = $new_pos;
	$self->{next}->[ $new_pos ] = -1;
}

sub find_prev {
	my ($self, $value) = @_;

	my $current = $self->{head};
	while ($current != -1) {
		return $current
			if ($self->{next}->[ $current ] != -1 && $self->{data}->[ $self->{next}->[ $current ] ] == $value);
		$current = $self->{next}->[ $current ];
	}
	
	return -1;
}

sub find {
	my ($self, $value) = @_;

	my $current = $self->{head};
	while ($current != -1) {
		return $current
			if ($self->{data}->[ $current ] == $value);
		$current = $self->{next}->[ $current ];
	}
	return -1;
}

sub erase {
	my ($self, $prev_pos) = @_;

	die "Out of range"
		if ($prev_pos == -1);

	my $pos;
	unless (defined $prev_pos) {
		$pos = $self->{head};
		$self->{head} = $self->{next}->[ $pos ];
		$self->{next}->[ $pos ] = $self->{first_empty};
		$self->{first_empty} = $pos;

		return;
	}
	$pos = $self->{next}->[ $prev_pos ];
	
	die "Out of range"
		if ($pos == -1);

	$self->{next}->[ $prev_pos ] = $self->{next}->[ $pos ];
	$self->{next}->[ $pos ] = $self->{first_empty};
	$self->{first_empty} = $pos;
}

sub to_arrayref {
	my $self = shift;

	my $res = [];
	my $pos = $self->{head};
	while ($pos != -1) {
		push @$res, $self->{data}->[$pos];
		$pos = $self->{next}->[ $pos ];
	}

	return $res;
}

1;