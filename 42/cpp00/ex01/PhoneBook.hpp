#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define FMT_LEN 10

#include "Contact.hpp"

class PhoneBook {
	public:
		void	add_contact(void);
		void	find_contact(void);
		void	display_contacts(void);

		PhoneBook(void);
		~PhoneBook(void);

	private:
		static const size_t max_contacts = 8;
		Contact contact_list[max_contacts];
		size_t	contact_idx;
};

#endif