// boluoxing.c ������
// by iceland

#include <ansi.h>
inherit NPC;

string ask_xueputi();

void create()
{
	set_name("������", ({ "boluo xing", "boluoxing" ,"boluo","xing"}));
	set("long",@LONG
��������İ�С��������˪֮ɫ��������ź�ɫ�Ķ��룬���ž�����Ǹ�������ˣ�
��Ϊ��Ľ�����µķ𷨺��书�����Ժ�ʦ���������С�
LONG
	);
	set("title", HIY "�����µ�ʮ��������" NOR);
	set("gender", "����");
	set("age", 29);
	set("attitude", "heroism");
	set("shen_type", -1);

	set("str", 25);
	set("int", 15);
	set("con", 25);
	set("dex", 30);

	set("max_qi", 1000);
	set("eff_jing", 400);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 40);
	set("combat_exp", 250000);
	set("score", 3500);

	set_skill("huanxi-chan", 80);
	set_skill("literate", 60);
	set_skill("force", 80);
	set_skill("longxiang-boruo", 80);
	set_skill("dodge", 80);
	set_skill("yuxue-dunxing", 80);
	set_skill("hand", 70);
	set_skill("dashou-yin", 70);
	set_skill("claw", 70);
	set_skill("tianwang-zhua", 70);
	set_skill("parry", 80 );
	set("unique", 1);

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("hand", "dashou-yin");
	map_skill("parry", "tianwang-zhua");
	map_skill("claw", "tianwang-zhua");

	prepare_skill("hand","dashou-yin");
	prepare_skill("claw","tianwang-zhua");

	create_family("������", 13, "����");
	set("class", "huanxi");

	set("inquiry", ([
//		"Ѫ����" : (: ask_xueputi :),
	]));
	set("puti_count", 1 + random(4));

	setup();
	carry_object(__DIR__"obj/gongde-jiasha")->wear();
	add_money("gold",1);
}
/*
string ask_xueputi()
{
	mapping fam; 
	object ob;
        
	if (!(fam = this_player()->query("family")) || fam["family_name"] !="������")
		return RANK_D->query_respect(this_player())+ "���Ǳ��ɵ��ӣ���ô�Ա�����ҩҲ��������ѽ��";

	if ( (int)this_player()->query_condition("neili_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + "�����࣬��Ѫ���磬�ǲ��ǸոճԹ�����ҩ���Ʋ��ף����Ҳ���˷ѣ�һ�������ɡ�";

	if (  present("xue puti", this_player()) )
		return RANK_D->query_respect(this_player())+ "�������ϲ����п�ҩ������������Ҫ�ˣ�����̰�����ᣡ";

	if ( (int)this_player()->query("max_neili") < 200 )
		return RANK_D->query_respect(this_player())+ "����������Ѫ��������к����档";

	if (query("puti_count") < 1) 
		return RANK_D->query_respect(this_player()) + "���ò��ɣ�����������Ҳû���ˡ�";

	ob = new( MEDICINE_D("xueputi") );
	ob->move(this_player());
	add("puti_count", -1);

	message_vision("$N���һ��Ѫ���ᡣ\n",this_player());
	return "�ðɣ���ס����ҩ����ʵ�ڲ��ף�����Ҫ�˷��ˡ�";
}
*/
