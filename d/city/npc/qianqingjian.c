// qianqingjian.Ǯ�ཡ
inherit NPC;
 
void create()
{
	set_name("Ǯ�ཡ", ({ "qianqing jian", "jian" }));
	set("nickname", "ɥ�Ÿ�");
	set("long", 
        "�����ǻƺ��Ĺ��Ǯ�ཡ��\n"
        " һ���ƻ���˵����ӡ�\n");
	set("gender", "����");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1800);
	set("max_jing", 800);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 280000);
	set("score", 100000);

    set_skill("force", 100);
    set_skill("xuantian-wuji", 100);
    set_skill("dodge", 120);

    set_skill("kunlun-shenfa", 120);
    set_skill("strike", 100);
    set_skill("parry", 100);
    set_skill("kunlun-zhang", 80);
    set_skill("literate", 60);
    map_skill("force", "xuantian-wuji");
    map_skill("dodge", "kunlun-shnfa");
    map_skill("strike", "kunlun-zhang");
  	map_skill("parry", "kunlun-zhang");
  	prepare_skill("strike", "kunlun-zhang");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
  	add_money("gold", 5);
}