//Cracked by Roath
// Modified by Kane, 6/9/97
#include <ansi.h>

inherit NPC_TRAINEE;
//inherit NPC;
string* dirs = ({
	"east", "west", "south", "north",
        "southeast", "southwest", "northeast", "northwest",
        "northdown", "southdown", "eastdown", "westdown",
        "northup", "southup", "eastup", "westup", "out",
        });

int return_home(object home);
void create()
{
	set_name("С����", ({ "xiaohong ma", "ma", "horse" }) );
        set("race", "����");
        set("age", 10);
	set("long", 
"����һƥ�񿥷Ƿ���"+HIR"��Ѫ����"NOR+"����˵�������·�����ʵ�����Ǵ���ɽ��Ұ��\n"
"����ɫĸ����ĺ����\n"
"�������Ϊ��������󷢱��䣬��ʦԶ������\n");
	
	set("attitude", "peaceful");
	set("wildness", 20000);
	set("value", 500);
	set("ability", 10);

	set("ridable", 1);
	set("str", 200);
        set("con", 200);
	set("dex", 200);
        set("int", 20);
	set("max_qi", 2000);
	set("qi", 2000);
	set("max_jingli", 1000);
	set("combat_exp", 100000);
        set_weight(200000);
	//call_out("checking", 1, this_object() );

        setup();
}

void init()
{
        object *ob, me = this_object();
        int my_jingli, my_mj, i, addjing;

        add_action("do_duhe","duhe");
        add_action("do_escape","whistle");

        my_jingli  = (int)me->query("jingli");
        my_mj = (int)me->query("max_jingli");
        addjing = (my_mj - my_jingli)/2;
        if(my_jingli <= my_mj/3){
        say(me->name() +"��ڴ�ڵش��Ŵ�����\n");
        return;
        }
        if(my_jingli <=30 && my_jingli > 20){
        say(me->name() +"ֻ�ڴ����������ؿ��ܲ����ˣ�\n");
        return;
        }
        if(my_jingli <=10){
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++){
        if (ob[i]->query("rided") == me);
        ob[i]->delete("rided");
        }
        me->delete("rider");
        me->unconcious();
        return;
        }
        if( environment(me)->query("resource/grass") &&
        me->query("food") < (me->max_food_capacity()*2/3)){
        me->set("food", (int)me->max_food_capacity());
        me->add("jingli", addjing);
        say(me->name() +"����ͷ�ڲݵ��ϳ��������\n");
        return;
        }
	add_action("do_tame", "train");
	add_action("do_tame", "tame");
	add_action("do_gen", "gen");
        add_action("do_gen", "come");
        add_action("do_ting", "ting");
        add_action("do_ting", "stay");
        add_action("do_fang", "fang");
        add_action("do_fang", "release");
}


int return_home(object home) {
	return 1;
}

int do_tame()
{
        return notify_fail("С���������޼���������Ԧ���������ˡ�\n");
}

int do_escape()
{
        object lord, user, room, env, me;
        mapping exit;
        int i, j;

        user = this_player();
        me = this_object();
	env = environment(me);

        if( !mapp(exit = env->query("exits")) && !j )
                return notify_fail("������·���ӡ�\n");

        for (i = 0; i < 12; i++) {
                if ( !undefinedp(exit[dirs[i]]))  
			room = find_object(exit[dirs[i]]);
	}
	
        if (!room && !j) return notify_fail("���������·���ӡ�\n");

        if( objectp(lord = me->query_lord()) 
	&& user->query("id") == lord->query("id")) {
        message_vision(HIW"С�����$N���������Լ�����һ�ӣ�����񱼾�����ȥ������\n"NOR, lord);
	lord->move(room);
	me->move(room);
	}
        return 1;
}
 
int do_duhe() {
	object me = this_object();
	object who = this_player();
	string dest;
	if (me->query("rider") != who) return 0;
	switch ((string)environment(who)->query("short")) {
	case "��ˮ�ϰ�":
		dest = "/d/shaolin/hanshui2";
		break;
	case "��ˮ����":
                dest = "/d/shaolin/hanshui1";
                break;
        case "�ų���":
                dest = "/d/xixia/xhbao";
                break;
        case "���ͱ�":
                dest = "/d/xixia/oldwall";
                break;
	case "������":
                dest = "/d/emei/baoguoxi";
                break;
        case "��������ǽ":
                dest = "/d/emei/jietuo";
                break;
        case "̫��":
                dest = "/d/taihu/matou";
                break;
        case "��ͷ":
                dest = "/d/taihu/taihu";
                break;
	default:
		return notify_fail("����û��С������Զɵĺӡ�\n");
	}
	message_vision("\n$N˫��һ��С����С����˻һ����Ծ��ˮ�н�$N�����԰���\n",who);
	message("vision", who->name() +"�������ȥ�ˡ�\n",
                environment(who), ({who}));
	me->move(dest);
	who->move(dest);
	message("vision", who->name() +"����ӺӶ԰������ˡ�\n",
                environment(who), ({who}));
	return 1;
}	

