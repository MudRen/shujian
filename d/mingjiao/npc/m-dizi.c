inherit NPC;
string *first_name = ({
"��","Ǯ","��","��","��","��","֣","��","��","��", "��","��" }); 
string *name_words = ({
"˳","��","��","��","��","��","��","��","־","��", "Т","��","��","��","��",
"��","��","ʢ","ʤ","��","��","��","ͬ","��", "��","��","��","¡","��","��","��","��","��","��" });
string *color_title = ({
"����н���","����н���","�״��н���","�����н���","�ϴ��н���","�̴��н���",
"�ƴ��н���","����н���","�����н���","�ڴ��н���", });

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))]; 
        if( random(10) > 4 ) 
        name += name_words[random(sizeof(name_words))];
        set_name(name, ({"nan jiaozhong", "jiaozhong", "nan"}) );
	set("title", color_title[random(sizeof(color_title))]);
	set("long", "����һ��"+this_object()->query("title")+"��������ר����־����ϰ����\n");
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
	set("combat_exp", random(10000)+15000);
        set_skill("force", 25+random(15));
        set_skill("shenghuo-shengong", 30);
        set_skill("dodge", 25+random(15));
        set_skill("piaoyi-shenfa", 30);
        set_skill("hand", 25+random(15));
        set_skill("yingzhua-shou", 30);
        set_skill("parry", 25+random(15));
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "piaoyi-shenfa");
        map_skill("parry", "yingzhua-shou");
        map_skill("hand", "yingzhua-shou");
        prepare_skill("hand", "yingzhua-shou");
	set("inquiry", ([
		"name": "������������ĩ�����ӣ���ʮ�������Ͷ������ѧ�ա�",
		"rumors": "��˵�ʽ���һ������������ǵ�������ɽ��һ��������",
		"here": "������������̳����û�»��ǲ�Ҫ�����ת�ĺá�",
		"����": "��ʲô�ʣ�������help mingjiao�𣿣�",
	]));
	setup();
	carry_object("/d/mingjiao/obj/black-cloth")->wear();
}
