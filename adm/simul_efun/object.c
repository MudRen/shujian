// object.c

varargs int getoid(object ob)
{
        int id;

        if (!ob) ob = previous_object();
        sscanf(file_name(ob), "%*s#%d", id);
        return id;
}

// Get the owner of a file.  Used by log_error() in master.c.
string file_owner(string file)
{
    string name;

    if (file[0] != '/') {
        file = "/" + file;
    }
    if (sscanf(file, "/u/%s/%*s", name)) {
        return name;
    }
   return 0;
}
int is_root(mixed ob)
{
        if (stringp(ob))
                return (SECURITY_D->get_status(ob) == "(admin)");

        if (objectp(ob))
        {
                if (geteuid(ob) == ROOT_UID)
                        // Root object want to execute
                        return 1;

                return (SECURITY_D->get_status(geteuid(ob)) == "(admin)");
        }

        return 1;
}
// domain_file should return the domain associated with a given file.
string domain_file(string file)
{
        string domain;

        if( sscanf(file, "/d/%s/%*s", domain) )
                return domain;

      return ROOT_UID;
}

// creator_file should return the name of the creator of a specific file.
string creator_file(string file)
{
        string *path;

        path = explode(file, "/") - ({ "" });
        switch (path[0]) {
                case "adm":
                        if (!strsrch(file, SIMUL_EFUN_OB))
                                break;
                case "cmds":
                        return ROOT_UID;
        }
        if (path[0] == "clone" && path[1] == "spec") return ROOT_UID;//������
        return "MudOS";
}

// author_file should return the name of the author of a specific file.
string author_file(string file)
{
        string name;

        if (sscanf(file, "/u/%s/%*s", name))
                return name;
     return ROOT_UID;
}

void destruct(object ob)
{
        if (ob) {
                if( previous_object() ) ob->remove( geteuid(previous_object()) );
                else ob->remove(0);
        }
        efun::destruct(ob);
}

object unew(string str)
{
        object ob = new(resolve_path(0, str));
        int i = ob->query("unique"), j, k;
        object *clone;

        if (!i) return ob;
        clone = filter_array(children(base_name(ob)), (: clonep :));
        j = sizeof(clone);
        while (j--) if (!clone[j]->query("clone_by_wizard")) {
                if (k = clone[j]->query_amount()) i -= k;
                else i--;
        }
        if (i < 0) destruct(ob);
        return ob;
}

