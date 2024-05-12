import PyPDF2

def compress_pdf(input_filename, output_filename, compression_level=None):
  """
  Compresses a PDF using PyPDF2.

  Args:
      input_filename: Path to the input PDF file.
      output_filename: Path to save the compressed PDF.
      compression_level (optional): Integer between 0 (no compression) 
                                     and 5 (maximum compression).
                                     Defaults to None (uses writer default).
  """
  with open(input_filename, 'rb') as pdf_file, open(output_filename, 'wb') as compressed_file:
    pdf_reader = PyPDF2.PdfReader(pdf_file)
    pdf_writer = PyPDF2.PdfWriter()

    for page in pdf_reader.pages:
      pdf_writer.addPage(page)

    if compression_level is not None:
      pdf_writer.downgrade()  # Remove unnecessary objects
      pdf_writer.set_metadata({})  # Remove metadata
      pdf_writer.set_compress(compression_level)  # Set compression level

    pdf_writer.write(compressed_file)

# Example usage
input_file =dqz_transformation.pdf
output_file = "compressed.pdf"
compress_pdf(input_file, output_file, compression_level=3)  # Adjust compression level as needed

