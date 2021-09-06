// shi.c ʷ��ɽ
// Modified by snowman 21/05/2000
// Modified by Looklove 2002.1.24
// changed ask ��͢��λ to  other file, and changed temp short to temp title

inherit NPC;
#include <ansi.h>

void create()
{
	object ob;
	set_name("ʷ��ɽ", ({ "shi qingshan", "shi", "qingshan" }));
	set("title", "����Ʒ�ر�");
	set("gender", "����");
	set("age", 33);
	set("str", 25);
	set("dex", 16);
	set("long", "�������䵱�׼ҵ��ӣ��ָ�ؤ���е����������ȴ�����˳�͢����\n");
	set("combat_exp", 200000);
	set("shen_type", 1);
	set("attitude", "heroism");

	set_skill("unarmed", 100);
	set_skill("tiyunzong",100);
	set_skill("yinyun-ziqi",100);
	set_skill("force", 100);
	set_skill("sword", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("stick", 100);
	set_skill("dagou-bang", 100);
	map_skill("parry", "dagou-bang");
	map_skill("stick", "dagou-bang");
	map_skill("dodge","tiyunzong");

	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/armor", 70);
	set_temp("apply/damage", 70);

	set("inquiry", ([
		"Ϊ��" : "��Ҫ������˼Ͷ����͢�Ļ�����ȥ����֪���ɡ�\n",
		"��Ч��͢" : "��Ҫ������˼Ͷ����͢�Ļ�����ȥ����֪���ɡ�\n",
	]));

	set("max_qi", 1700);
	set("qi", 1700);
	set("neili", 2000);
	set("max_neili", 2000);
	set("eff_jingli", 2000);
	set("jiali", 30);

	setup();

	if (clonep()) {
		ob = unew(BINGQI_D("langya-bang"));
		if(!ob) ob= new(BINGQI_D("stick"));
		ob->move(this_object());
		ob->wield();
		carry_object(ARMOR_D("armor"))->wear();
		carry_object(ARMOR_D("guanxue"))->wear();
        }
}

int accept_fight(object me)
{
       command("say �Ϸ��δ�ͽ����˶��ֹ����ˣ�����Ҳ����������");
       return 0;
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && living(this_object()) &&
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
	}
}

void die()
{
	object killer;
	if(objectp(killer = query_temp("last_damage_from")) ){
		killer->add_condition("killer", 30);
		command("say "+killer->name()+"�㾹��ıɱ��͢���٣����˰�������");
	}
        ::die();
}
