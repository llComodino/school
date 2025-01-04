<?php
require('fpdf.php');

class AssociateCardGenerator extends FPDF
{
    protected $imgpath = '';
    protected $name    = '';
    protected $surname = '';
    protected $bdate   = '';
    protected $phone   = '';
    protected $email   = '';

    function Header()
    {
        $this->Image($this->imgpath, 10, 6, 30);
        $this->SetFont('Arial', 'B', 15);
        $this->Cell(80);
        $this->Cell(30, 10, implode(" ", [$this->name, $this->surname]), 1, 0, 'C');
        $this->Ln(20);
    }

    function Footer()
    {
        $this->SetFont('Arial', 'B', 15);
        $this->Cell(65);
        $this->Cell(60, 10, "Welcome to the club!", 1, 0, 'C');
        $this->Image("./imgs/logo.png", x:170, w:30);
        $this->Ln(20);
    }

    public function body() {
        $this->SetFont('Arial', '', 15);
        $this->Cell(75);
        $this->Cell(40, 10, $this->name,    1, 1, 'C');
        $this->Cell(75);
        $this->Cell(40, 10, $this->surname, 1, 1, 'C');
        $this->Cell(75);
        $this->Cell(40, 10, $this->bdate,   1, 1, 'C');
        $this->Cell(75);
        $this->Cell(40, 10, $this->email,   1, 1, 'C');
        $this->Cell(75);
        $this->Cell(40, 10, $this->phone,   1, 1, 'C');
        $this->Ln(10);
    }

    public function __construct($data, $imgpath)
    {
        parent::__construct('L', size:'A5');
        if (!$imgpath) return;

        $this->bdate   = array_pop($data);
        $this->phone   = array_pop($data);
        $this->email   = array_pop($data);
        $this->surname = array_pop($data);
        $this->name    = array_pop($data);

        $this->set_image_path($imgpath);
    }

    private function set_image_path($path)
    {
        if (!$path) return;
        $this->imgpath = $path;
    }
}
