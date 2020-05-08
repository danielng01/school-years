part of contacts;
//WORK IN PROGRESS
/** Options used with [Contacts.find] method.*/
class ContactsFindOptions {
  /** The search string used to filter Contacts; default "" */
  final String filter;
  /** Whether return multiple Contacts; default false */
  final bool multiple;

  ContactsFindOptions({this.filter : "", this.multiple : false});

  Map _toMap() => {'filter' : this.filter, 'multiple' : this.multiple};
}