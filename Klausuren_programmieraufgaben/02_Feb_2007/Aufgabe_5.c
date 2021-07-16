//Funktionsdekleration

Email *createEmail(char *From, char *To, char *Subject, char *Body);
void destroyEmail(Email *);
void insertEmail(Mailbox *, Email *);

//Funktionsdefinition

Email *createEmail(char *From, char *To, char *Subject, char *Body)
{
    Email ** = NULL;
    e = (Email *) calloc(1, sizeof(Email));
    if (!e)
    {
        getMem(e->From);
        getMem(e->To);
        getMem(e->Subject);
        getMem(e->Body);
    }
    return e;
}

void destroyEmail(Email *)
{
    if(e)
    {
        free(e->Form);
        free(e->To);
        free(e->Subject);
        free(e->Body);
        free(e);
    }
}

void insertEmail(Mailbox *, Email *)
{
    if(m)
    {
        m->Email[m->AnzEmails];
        m->AnzEmails ++;
    }
}

