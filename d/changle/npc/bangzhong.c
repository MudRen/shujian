inherit NPC;
string *first_name = ({
"��","Ǯ","��","��","��","��","֣","��","��","��", "��","��" }); 
string *name_words = ({
"˳","��","��","��","��","��","��","��","־","��", "Т","��","��","��","��",
"��","��","ʢ","ʤ","��","��","��","ͬ","��", "��","��","��","¡","��","��","��","��","��","��" });


void create()
{
	string name;
	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))]; 
	if( random(10) > 4 ) 
	name += name_words[random(sizeof(name_words))];
	set_name(name, ({"bang zhong", "bang", "zhong"}) );
	set("title", "���ְ����");
	set("long", "����һ������Ϊ�������ĳ��ְ��ڡ���������ת���ƺ�������ʲô�����⡣\n");
	set("gender", "����" );
	set("age", 16+random(20));
	set("attitude", "peaceful");
	set("str",15+random(13));
	set("int",20);
	set("con",15+random(12));
	set("dex",15+random(10));
	set("max_qi", 300+random(200));
	set("max_jing", 200)+random(200);
	set("neili", 250+random(200));
	set("max_neili", 250+random(200));
	set("combat_exp", random(10000)+50000);

	set_skill("force", 25+random(15));
	set_skill("shenzhao-jing", 30);
	set_skill("dodge", 25+random(15));
	set_skill("piaoyi-shenfa", 30);
	set_skill("hand", 25+random(15));
	set_skill("yingzhua-shou", 30);
	set_skill("parry", 25+random(15));
	set_skill("jinwu-daofa", 40);
	set_skill("blade", 40);

	map_skill("force", "shenzhao-jing");
	map_skill("dodge", "piaoyi-shenfa");
	map_skill("parry", "yingzhua-shou");
	map_skill("hand", "yingzhua-shou");
	map_skill("blade", "jinwu-daofa");
	prepare_skill("hand", "yingzhua-shou");

	setup();
	carry_object(BINGQI_D("blade"))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
}
