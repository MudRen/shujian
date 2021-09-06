// ���� by leontt

inherit NPC;
#include <ansi.h>

string ask_fish();
string ask_yideng(string name);

void create()
{
	set_name("����", ({ "yu ren", "yu", "ren" }) );
	set("long", "����ԼĪ��ʮ������ͣ�һ�ź�����Ĺ��������������������������\n");
	set("gender", "����" );
	set("age", 45);
	set("str", 30);
	set("con", 30);
	set("dex", 25);
	set("int", 25);
	set("per", 20);
	set("unique", 1);
	set("attitude", "friendly");

	set("max_qi", 5000);
	set("max_jing", 2800);
	set("eff_jingli", 3600);
	set("neili", 8000);
	set("qi", 5000);
	set("jingli", 3600);
	set("max_neili", 8000);
	set("jiali", 50);

	set("combat_exp", 2300000);
	set("score", 5000);

	set_skill("parry", 280);
	set_skill("dodge", 280);
	set_skill("force", 280);
	set_skill("literate", 200);
	set_skill("qiantian-yiyang", 280);
	set_skill("tianlong-xiang", 280);
	set_skill("finger", 280);
	set_skill("yiyang-zhi", 280);
	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "yiyang-zhi");
	map_skill("force", "qiantian-yiyang");
	map_skill("finger", "yiyang-zhi");
	prepare_skill("finger","yiyang-zhi");

	set("inquiry", ([
		"������" : "�����޾��ǽ�ɫ�������㡣",
		"һ�ƴ�ʦ" :(: ask_yideng, "һ�ƴ�ʦ" :),
		"�λ�ү" : (: ask_yideng, "�λ�ү" :),
	]));
	setup();

	carry_object(ARMOR_D("b_cloth"))->wear();
	carry_object(ARMOR_D("caoxie"))->wear();
}

string ask_yideng(string name)
{
	object me= this_player();

	if ( name == "�λ�ү" )
		return "�λ�ү���Ѳ��ڳ����ˣ�";

	if ( me->query_temp("yideng/boat"))
		return "�Ҳ����Ѿ���������ɽ�ķ�����ô��";

	if ( me->query_temp("yideng/yuren"))
		return "������ȥ�ҵĽ������أ�";

	if ( name == "һ�ƴ�ʦ" ){
		me->set_temp("yideng/yuren", 1);
		return "Ҫ����ʦ����Ҳ���ѣ������Ҹն�ʧ�����������ޣ���֪��λ"+RANK_D->query_respect(me)+"�ܷ����ץ�ء�";
	}
}

int accept_object(object me, object ob)
{
	if ( ob->query("id") != "jin wawa" ){
		command("say ���������Ҹ���");
		return 0;
	}
	if ( ob->query_temp("owner") != me->query("id")){
		command("say �������õ���Խ����ް���");
		return 1;
	}
	message_vision(CYN"$N������β�����������з������������۶��У�������䣬����Ц�������ֲ�\n"+
			"�ý��������㣬��Ȼ��С�����޽�һ�㡣��\n"+
			HIW"\n$N���ֽ���$n����$nϲ��ü�ң��������������ֽ��˹�ȥ��\n\n"NOR, me, this_object());
	me->delete_temp("yideng");
	me->set_temp("yideng/boat", 1);
	me->add_busy(1);
	call_out("give_bonus", 1, me, this_object());
	call_out("dest", 1, ob);
	return 1;
}

void dest(object ob)
{
	if ( !ob) return;
	destruct(ob);
}

int give_bonus(object me, object ob)
{
	object boat, jiang;

	message_vision("\n", me);
	command("say ����ɽ˵�����ѣ�˵��ȴҲ���׵ý���������ת��ɽ�ǣ��ѷ���\n"+
		"������һ������������������֮�У��⶯�������ڼ������������ϾͿ����ˡ�");
	boat = unew(__DIR__"../obj/boat");
	jiang= unew(__DIR__"../obj/jiang");
	boat->move(me);
	jiang->move(me);
	message_vision("$N����$nһ��"HIB"����"NOR"��\n",this_object(), me);
	message_vision("$N����$nһ��"BLU"����"NOR"��\n",this_object(), me);
	return 1;
}
