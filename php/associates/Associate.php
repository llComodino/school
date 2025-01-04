<?php
include 'AssociateCardGenerator.php';

class Associate
{
    const _FILEPATH = "./associates.txt";
    protected $_info = [];

    public function set_info($data)
    {
        if (!is_array($data)) return;
        $this->_info = $data;
    }

    public function extract_from_file($offset = 0)
    {
        try {
            $file = fopen(self::_FILEPATH, "r");
            if (!$file) throw new Exception("Error opening file: " . self::_FILEPATH);

            if ($offset) {
                fseek($file, $offset, SEEK_SET);
            }

            $str = fgets($file);
            $data = explode(";", $str);
            $new_info = [];
            $keys = array_keys($this->_info);

            if (count($keys) != count($data)) throw new Exception("Error while extracting from file.\nMismatched count of keys and data");
            else foreach ($keys as $pos => $key) {
                $new_info[$key] = $data[$pos];
            }

            $this->set_info($new_info);
        } catch (Exception $e) {
            echo "Excpetion catched: " . $e->getMessage();
        } finally {
            fclose($file);
        }
    }

    public function save_to_file()
    {
        try {
            $file = fopen(self::_FILEPATH, "a");
            if (!$file) throw new Exception("Error opening file");

            fwrite($file, $this->to_string() . "\n");
        } catch (Exception $e) {
            echo "Error: " . $e->getMessage();
        } finally {
            fclose($file);
        }
    }

    public function find_associate($name)
    {
        $found = false;
        $offset = 0;
        try {
            $file = fopen(self::_FILEPATH, "r");
            if (!$file) throw new Exception("Error opening file");

            while (($str = fgets($file))) {
                $cur_name = explode(";", $str)[0];
                if ($name == $cur_name) {
                    $found = true;
                    break;
                }
                $offset += strlen($str);
            }
        } catch (Exception $e) {
            echo "Error: " . $e->getMessage();
        } finally {
            fclose($file);

            if ($found) $this->extract_from_file($offset);
        }
        return $found;
    }

    public static function get_all()
    {
        $str = '';
        try {
            $file = fopen(self::_FILEPATH, "r");
            if (!$file) throw new Exception("Error opening file");

            while (!feof($file)) {
                $str .= fgets($file);
            }
        } catch (Exception $e) {
            echo $e->getMessage();
        } finally {
            fclose($file);
        }

        return $str;
    }

    public function create_card($path)
    {
        $data = $this->_info;
        if (count($data) != 7) return;

        array_pop($data); // removes password
        array_pop($data); // removes id type

        $card = new AssociateCardGenerator($data, $path);
        $card->AddPage();
        $card->body();

        $card->Output('F', './tmp.pdf');

        return "<p>We have generated you card, download it before we overwrite it: <a href=\"./tmp.pdf\">Card</a></p>";
    }

    public function to_string()
    {
        return implode(";", $this->_info);
    }
};
