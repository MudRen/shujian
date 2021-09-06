// kanyaodizi ��Ҥ����
// Made By keepon at 99.08.15

inherit NPC;

string ask_work1();
string ask_work2();
string ask_houshan();

void create()
{
	set_name("��Ҥ����", ({ "kanyao dizi", "di zi", "dizi", "kanyao" }));
	set("long", "���Ƕ���ɽ�ĵ�������ӣ����ڴ˿���̿Ҥ�ġ�\n");
	set("gender", "����");
	set("title", "�����ɵ��������");
	set("age", 30);
	set("str", 50);
	set("int", 20);
	set("con", 20);
	set("dex", 50);
	set("combat_exp", 100000);
	set("shen", 0);
	set("attitude", "peaceful");
	set("max_qi",1800);
	set("max_jing",1800);
	set("neili",1600);
	set("max_neili",1600);
	set("jiali",10);

	set_skill("sword", 80);
	set_skill("huifeng-jian", 80);
	set_skill("parry",80);
	set_skill("linji-zhuang", 80);
	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("anying-fuxiang",80);

	map_skill("force", "linji-zhuang");
	map_skill("dodge", "anying-fuxiang");
	map_skill("parry", "huifeng-jian");
	map_skill("sword", "huifeng-jian");

	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set("inquiry", ([
		"��ľ": (: ask_work1() :),
		"��̿": (: ask_work2() :),
//		"��ɽ": (: ask_houshan() :),
//		"����": (: ask_houshan() :),
	]) );

	setup();
	carry_object("/d/emei/obj/cloth2")->wear();
	carry_object("/d/emei/obj/shoes2")->wear();
	carry_object("/d/emei/obj/changjian")->wear();
}

string ask_work1()
{
	object me=this_player();
	int lvl = (int)me->query_skill("linji-zhuang", 1);

	if( me->query("family/family_name") != "������" || me->query("class") == "bonze" )
		return "��λ"+ RANK_D->query_respect(me) + "���Ƕ����׼ҵ��ӣ������Ͷ����Ĵ�ݣ�";
	if ( lvl > 100 )
		return "��Ĺ���̫�ߣ���Щ�ֻ���õͱ�����ȥ�ɰɡ�";
	if( me->query_temp("emjob2/��ľ") )
		return "�����Ѿ�����ȥ������ô�������д��ţ�";
	me->set_temp("emjob2/��ľ", 45 - ((int)me->query("str")) );
	return "�����ɵĵ��Ӿ͵óԿ����͡��ðɣ�����͵���ɽ������ŪһЩľ������";
}

string ask_work2()
{
	object me=this_player();
	int lvl = (int)me->query_skill("linji-zhuang", 1);
	if( me->query("family/family_name") != "������" || me->query("class") == "bonze" )
		return "��λ"+ RANK_D->query_respect(me) + "���Ƕ����׼ҵ��ӣ������Ͷ����Ĵ�ݣ�";
	if ( lvl > 100 )
		return "��Ĺ���̫�ߣ���Щ�ֻ���õͱ�����ȥ�ɰɡ�";
	if( (int)me->query_temp("emjob2/��ľ") != 1)
		return "�������ŪЩ������̿��ľ������";
	if( me->query_temp("emjob2/��̿") )
		return "�����Ѿ�����ȥ��������ô���д��ţ�";
	me->set_temp("emjob2/��̿", 10 + random((int)me->query("per")));
	me->set_temp("emjob2/uptime", uptime() );
	return "�ðɣ����������̿�ɡ�";
}

string ask_houshan()
{
	object me=this_player();
	int lvl = (int)me->query_skill("linji-zhuang", 1);
	if ( (int)lvl/10 == 14 ) me->set("emsujia", 0);
	if ( (int)lvl/10 == 16 ) me->set("emsujia", 1);
	if ( lvl < 140 ) return "��ɽ��һ��ɽ������������ó�����������ڹ����������\n";
	tell_object(me, "��Ȼ���ʵ��ˣ����Ҿʹ���ȥ�ɡ�\n");
	me->move("/d/emei/houshanxlsd");
	return "��һ�������ӡ�\n";
}
