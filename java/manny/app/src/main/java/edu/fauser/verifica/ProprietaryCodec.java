package edu.fauser.verifica;

class ProprietaryCodec extends Codec {
  final String vendor_id = "0A:CC:91:D3:FF:F4";
  final String website = "software.vendor.com";

  ProprietaryCodec(Codec codec) {
    super(codec.code, codec.exec, codec.format);
  }

  @Override
  public String toString() {
    return "Vendor ID: " + this.vendor_id + "\nWebsite: " + this.website + "\n\n";
  }
}
