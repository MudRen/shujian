#include <ansi.h>

inherit NPC;
string color,cname,info;
void create_weapon(object client);
void remove_serving(object me);

string ansi_convert(string str)
{
        str = replace_string(str, "$BLK$", BLK);
        str = replace_string(str, "$RED$", RED);
        str = replace_string(str, "$GRN$", GRN);
        str = replace_string(str, "$YEL$", YEL);
        str = replace_string(str, "$BLU$", BLU);
        str = replace_string(str, "$MAG$", MAG);
        str = replace_string(str, "$CYN$", CYN);
        str = replace_string(str, "$WHT$", WHT);
        str = replace_string(str, "$HIR$", HIR);
        str = replace_string(str, "$HIG$", HIG);
        str = replace_string(str, "$HIY$", HIY);
        str = replace_string(str, "$HIB$", HIB);
        str = replace_string(str, "$HIM$", HIM);
        str = replace_string(str, "$HIC$", HIC);
        str = replace_string(str, "$HIW$", HIW);
        str = replace_string(str, "$NOR$", NOR);
        return str;
}

void create()
{
        set_name("Ѧ��", ({ "xue zhu", "xue", "zhu" }));
        set("gender", "����");
        set("age",42);
	set("long","����һλ������˪������󺺣�ֻ����˫�ֵ�Ĵָʳָ���Ѳ�����ֻʣ��������ָ��\n");
	set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);
	set("combat_exp", 40000);
	set("attitude", "friendly");
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
        object  ob;

        add_action("do_ding", "make");
        add_action("do_yes","yes");
        add_action("do_no","no");
        ::init();
         if(interactive(ob = this_player()) && visible(ob))
                say("Ѧ�����˸���˵������λ"+RANK_D->query_respect(ob)+"�����\n");
}

int do_ding(string str)
{
        object ob = this_object();
        object me = this_player();

	if(me->query_skill("staff", 1) < 50 || !me->query_skill_mapped("staff")){
		command("say �Բ�����������ָ�Ѷϣ�ֻ�ܴ�Щ���ȳ�����\n");
		return 1;
	}
	me->delete_temp("xue/order");
	if(!(str) || sscanf(str, "%s %s",color,cname) != 2)
		return notify_fail("�� <make ������ɫ ��������> ������������ȡ�\n");
	if(ob->query_temp("serving")){
		command("say �Բ���ѽ������æ���أ�\n");
		return 1;
	}
	ob->set_temp("serving",1);
	ob->start_call_out( (: call_other,this_object(), "remove_serving",ob :), 60 );

	cname = sprintf("%s%s",color,cname);
	cname = ansi_convert(cname);
	info = sprintf("\n���ȵ��������ǣ�%s\n",cname);
	message_vision(HIY"$N����$n�Ȼ��˰��죬����$N�������һ������"+cname+HIY"���¸��ȡ�\n"NOR, me, ob);
	command("nod");
	command("say ��ȷ������Ҫ���������"+info+GRN"  (ȷ�����<yes|no>)"NOR);
	me->set_temp("xue/order",1);
	return 1;
}

int do_yes()
{
	object me = this_player();
	if(me->query_temp("xue/order")){
		if(MONEY_D->player_pay(me,30000) == 1)   //weapon's price 3 gold
			create_weapon(me);
		else{
			remove_call_out("remove_serving");
			this_object()->delete_temp("serving");
			me->delete_temp("xue/order");
			return  notify_fail("�����ϴ���Ǯ�����ˣ�\n");
		}
		return 1;
	}
	return 0;
}
int do_no()
{
	object me = this_player();
	if(me->query_temp("xue/order")){
		this_object()->delete_temp("sreving");
		tell_object(me,"��������Ҫ���´���ʲô���ı�����\n");
		remove_call_out("remove_serving");
		me->delete_temp("xue/order");
		return 1;
	}
	return 0;
}

void create_weapon(object me)
{
        object ob = this_object();
        object weapon;
        int str,damage,weight;
        str = me->query_str();
        damage = str+random(15);

	if(damage >= 60) damage = 60;
        weapon = new("/clone/weapon/gangzhang");
        weapon->set("name",cname + NOR);
        weapon->set("long", "����һ����Ѧ������"+me->name()+"��"+weapon->query("name")+"��\n");
        weapon->set("value",0);
        weapon->set("no_drop",1);
        weapon->set("no_get",1);
        weight = random(weapon->query_weight() * 2 * str / 30 +1);
        weapon->set("weapon_prop/damage",damage);
        weapon->set_weight(weight);
        weapon->move(me);
        command("say ��ı���������ˡ�\n");
        message_vision("$N����$nһ���´����"+weapon->query("name")+"��\n", ob,me);
        ob->delete_temp("serving");
        me->delete_temp("xue/order");
}

void remove_serving(object me)
{
	me->delete_temp("serving");
}
