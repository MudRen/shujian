#include <ansi.h>

inherit F_CLEAN_UP;

int main(string str)
{
        object *ob;
        object where;
		int i;
		int nNPC=0,nPlayer=0,nDeleted=0;
        ob=livings();
        i = sizeof(ob);
        while (i--) {
			if(!ob[i]||!objectp(ob[i]))continue;
			nNPC++;
			if( userp(ob[i]) )nPlayer++;

			where=environment(ob[i]);
			if(!where||!objectp(where)){
				write(sprintf("Delete %s(%s) for having no environment.\n",ob[i]->query("id"),file_name(ob[i]) ) );
				if(!userp(ob[i])){
		//			destruct(ob[i]);
					nDeleted++;
				}
				else ob[i]->move(environment(this_player()));
				continue;
			}

			if( !userp(ob[i]) && sizeof(children(base_name(ob[i])+".c") ) > 10 )
			{
				    write( sprintf("Delete %s(%s) for multiple copies.\n",ob[i]->query("id"),file_name(ob[i]) ) );
					if( ob[i] && objectp(ob[i]) )
					{
		//				destruct(ob[i]);
						nDeleted++;
						continue;
					}
			}

			write(sprintf("%s(%s,%s) in %s(%s)\n",ob[i]->query("name"),ob[i]->query("id"),file_name(ob[i]),where->query("short"),file_name(where)));
        		ob[i]->set_temp("last_damage_from", "½ÙºóÓàÉú");
 
			call_out("buchang", random(30), ob[i]);
        }
		write(sprintf("\n\nTotal NPC+Player number: %d where %d are players.\n%d NPC destructed for no environment.\n\n",nNPC,nPlayer,nDeleted) );

        return 1;
}
void buchang(object ob)
{
      if (ob) ob->clear_condition("sl_poison");
}
