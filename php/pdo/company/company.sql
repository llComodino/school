create table tirocinante (
	matricola char(16) primary key,
	nome varchar(32) not null default(''),
	cognome varchar(32) not null default(''),
	classe enum('Quarta', 'Quinta') not null default('Quinta'),
	idazienda char(16) not null,
	idtutor char(16) not null
);

create table azienda (
	id char(16) primary key,
	nome varchar(32) not null default(''),
	luogo,
	settore,
	tipologia
);

create table tutor (
	id char(16) primary key,
	nome varchar(32) not null default(''),
	cognome varchar(32) not null default(''),
	materia
);
