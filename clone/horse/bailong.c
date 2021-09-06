//Cracked by Roath
// Jay 5/1/97
// Modified by Ryu.

inherit NPC_TRAINEE;
//inherit NPC;

int return_home(object home);
void create()
{
	set_name("������", ({ "bailong ma", "ma", "horse" }) );
        set("race", "����");
        set("age", 10);
	set("long", "����һƥ���ޱȵİ���������������һǧ��ҹ�а˰١��ɺ�Ҳ���������ֺ�Ϸ��\n");
/*	set("msg_fail", "$n����$Nŭ˻һ��������������");
        set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
        set("msg_trained","$n��˻һ�����ߵ�$N��߰����������Ե�ʮ�ָ��ˣ�");
 */
       set("attitude", "peaceful");
	set("wildness", 10000);
	set("value", 200);
	set("ability", 5);

	set("ridable", 1);
	set("str", 150);
        set("con", 140);
	set("dex", 150);
        set("int", 20);
	set("max_qi", 1800);
	set("qi", 1800);
	set("max_jingli", 850);
	set("combat_exp", 35000);
        set_weight(200000);
	//call_out("checking", 1, this_object() );

        setup();
}

void init()
{
        object *ob, me = this_object();
        int my_jingli, my_mj, i, addjing;

        add_action("do_duhe","duhe");
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
        return notify_fail("�����������޼���������Ԧ���������ˡ�\n");
}

int do_duhe()
{
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
	default:
		return notify_fail("����û�а�������Զɵĺӡ�\n");
	}
	message_vision("\n$N˫��һ�а������������Ծ��ˮ�н�$N�����԰���\n",who);
	message("vision", who->name() +"�������ȥ�ˡ�\n",
                environment(who), ({who}));
	me->move(dest);
	who->move(dest);
	message("vision", who->name() +"����ӺӶ԰������ˡ�\n",
                environment(who), ({who}));
	return 1;
}	

