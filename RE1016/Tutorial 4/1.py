from msilib.schema import Error


emails = ['chayhuixiang@gmail.com','abc@xyz.sg']
def converter(emails):
    emailTupleList = [tuple(email.split('.')) for email in emails]
    return emailTupleList
print(converter(emails))