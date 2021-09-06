#include <ansi.h>
#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_SAVE;

nosave int last_age_set;
string userid;

void quit(object ob);
varargs void create(string arg)
{
	::create();
	set_name("��̨�������", ({ arg }) );
	userid = arg;
}

void reset()
{
	if (!query("jingli"))
		set("jingli", 10);
}

int save() { return 0; }
int set_leader(object ob){ return 0; }

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = query("id");
	if( !id ) id = getuid();
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

// This function updates player's age, called by heart_beat()
void update_age()
{
        int hour, age = 14, month, modify = query("age_modify");

        // Update the time we spend on mudding, using method from TMI-2 mudlib.
        delete("age_modify");
        if( !last_age_set ) last_age_set = time();
        hour = add("mud_age", time() - last_age_set) / 3600;
        if (hour <=144) {
                age += hour / 24;
                month = (hour % 24) / 2;
        } else {
                hour -= 144;
                age = 20;
                while ((hour -= age*3 - 33) >= 0) age++;
                month = (hour + age*3 - 33) * 12 / (age*3 - 33);
        }
        if (modify > 0)
                while (modify--) {
                        add("mud_age", 86400);
                        if (age > 19) add("mud_age", (age-19)*10800);
                        age++;
                }
        else
                while (modify++) {
                        add("mud_age", -86400);
                        if (age > 20) add("mud_age", (20-age)*10800);
                        age--;
                }
        last_age_set = time();
        set("month", month);
        set("age", age);
}

void setup()
{
	// We want set age first before new player got initialized with
	// random age.
	update_age();

	::setup();
}

void die()
{
	string fam, color;
        object me, ob;
        
        me = this_object();
        ob = me->query_temp("last_damage_from");
        if( !living(this_object()) ) this_object()->revive(1);
        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());
        fam = me->query("family/family_name")?me->query("family/family_name"):"ƽ�����";
        color = me->query("color")?me->query("color")+" ":" ";
        fam = HIW+fam+NOR+color+ me->name(1) + "(" + capitalize(me->query("id")) + ")";
        if(objectp(ob))
        	environment(me)->end_fight(me, ob, fam);

        if(objectp(ob)) quit(ob);
        quit(me);
}

void quit(object ob)
{
	
	object link_ob;

	if(!ob) return;
	link_ob = ob->query("link_ob");
	if(ob->query_temp("quest/bwzh/leitai"))
		message_vision("\n$N�˳�����̨��\n\n", ob);
	if(environment(ob)->query_temp("quest/bwzh/leitai") > 0) 
		environment(ob)->add_temp("quest/bwzh/leitai", -1);
	
	if(objectp(link_ob)){           
		if(link_ob->query_temp("apply/short"))
			link_ob->delete_temp("apply/short");   
		if( !query_temp("netdead") && link_ob->is_character() ) {
			tell_object(ob, "��ӱ�����̨������������\n"NOR);
                        exec(link_ob, ob);
                }
        }
	if(link_ob->query_temp("quest/bwzh/biwu_host"))
	{
		link_ob->set_temp("apply/short", ({link_ob->name()+"("+link_ob->query("id")+")"YEL" <���������У�������> "NOR}));

	}
	else if(link_ob->query_temp("quest/bwzh/hoster"))
		link_ob->set_temp("apply/short", ({link_ob->name()+"("+link_ob->query("id")+")"YEL" <����������> "NOR}));
	
	seteuid(ROOT_UID);
	destruct(ob); 
}

private void net_dead()
{
	object ob = query("link_ob");

	set_temp("netdead", time());
        set_heart_beat(0);
        tell_room(environment(), query("name") + "�����ˡ�\n", this_object());
	if (ob) ob->net_dead();
	die();
}

void reconnect()
{
	object ob = query("link_ob");

	set_heart_beat(1);
	delete_temp("netdead");
	tell_object(this_object(), "����������ϡ�\n");
	if (ob) {
		ob->reconnect();
		ob->set_temp("link_ob", query_temp("link_ob"));
	}
}
