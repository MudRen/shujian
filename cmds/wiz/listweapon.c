#include <ansi.h>

int main()
{
        object *ob;
        string msg;
        int i;
        
        
        ob=objects();
        ob=filter_array(ob,(: environment($1) && ($1->query("rigidity")>5 || $1->query("sharpness")>5) :));
        
        msg=HIC"\n��"+MUD_NAME+"�����б�\n"NOR;
        msg+=HIB"�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y\n"NOR;
        i=sizeof(ob);
        while(i--) {
                msg+=sprintf("%-20s %10s Ӳ�ȣ�%-5d �����ȣ�%-5d\n",
                        ob[i]->query("name")+"("+ob[i]->query("id")+")",
                        environment(ob[i])->short(),
                        ob[i]->query("rigidity"),
                        ob[i]->query("sharpness"),
                        );
                }
                
        msg+=HIB"�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y\n"NOR;

        this_player()->start_more(msg);
        return 1;
}