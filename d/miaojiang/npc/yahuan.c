// /u/dubei/miaojiang/yahua
 
inherit NPC;

void create()
{
        set_name("Ѿ��", ({ "ya huan", "ya", "huan" }));
        set("gender", "Ů��");
        set("age", 16);      
         set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("combat_exp", 13000);
        set("shen", 1);
        set("attitude", "peaceful");
	set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
	set("jiali",30);
	set("score", 8000);

        set_skill("cuff", 50);
	set_skill("parry",40);
	set_skill("tiyunzong",70);
        set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("yinyun-ziqi",70);

	map_skill("force","yinyun-ziqi");
	map_skill("dodge","tiyunzong");
        
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
     
//        carry_object(__DIR__"obj/shoe")->wear();
        carry_object("/clone/armor/cloth")->wear();
       
        set("inquiry", ([
          "here" : "������ҩ���ӡ��Ҽ�С�㾫ͨ����ҩ�䣬����֮ҩ����������֮Ч��\n",
          "rumors" : "�嶾������ɲ������ȥ������Ķ���������\n",
         
 ]));           
}