// �����ŵ���

inherit NPC;
void create()
{
        set_name("�����ŵ���", ({ "yellow dizi","dizi" }));
	set("long", "����һ�������̻����ŵĵ��ӡ�\n");
        set("gender", "����");
	set("title", "�����̵���������");	
        set("age", 20);       
	set("str", 17);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("per", 15);
        set("combat_exp", 40000);
        set("shen", -1000);
        set("attitude", "peaceful");
	set("max_qi",400);
        set("max_jing",300);
        set("neili",400);
        set("max_neili",400);
        set("jingli",150);
        set("eff_jingli",150);
	set("jiali",0);
	set("score", 7000);

      //set_skill("unarmed", 100);
	set_skill("force", 40);
	set_skill("dodge", 40);
       //set_skill("move", 80);
      set_skill("parry",40);
	set_skill("strike",40);
      set_skill("huagu-mianzhang", 40);
      set_skill("youlong-shenfa",40);
      set_skill("dulong-dafa",40);
      
	map_skill("force", "dulong-dafa");
	map_skill("dodge", "youlong-shenfa");
	//map_skill("move", "youlong-shengfa");
       map_skill("strike", "huagu-mianzhang");
      //map_skill("unarmed","huagu-mianzhang");
      map_skill("parry","huagu-mianzhang");
      
      create_family("������",3, "����");
      setup();
      carry_object(__DIR__"obj/ycloth")->wear();     
}
