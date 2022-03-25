# Write a function that takes a list of email addresses as an argument and returns a list of tuples of 
# username and domains.

emails = ['chayhuixiang@gmail.com','abc@xyz.sg']
def converter(emails):
    emailTupleList = [tuple(email.split('.')) for email in emails]
    return emailTupleList
print(converter(emails))