// fengtiannan.c

inherit NPC;

void create()
{
        set_name("������", ({ "feng tiannan", "feng" }));
        set("long", "���������廢���������ϰ�������ϡ�
ֻ�����ϴ�������Ʋ����С�ڣ�ԼĪ��ʮ������ͣ������һֻ������
��������һ�������̺���ٲȻ�Ǹ������ŵĴ�����ģ����ʵ���Ƹ�
���ط��ߵ����ֶ�ԣ�ֻ�ǽŲ����ȣ�˫Ŀ����������书��ǿ��
\n");
        set("gender", "����" );
	set("attitude", "peaceful");
        set("age", 55);
        set("no_get", "�����϶������̫���ˡ�\n");
        set("unique", 1);
	set("shen", -10000);

	set("str", 30);
        set("int", 20);
        set("con", 10);
        set("dex", 20);

	set("max_qi",2500);
        set("max_jing",2500);
        set("neili",3500);
        set("max_neili",3500);

        set("jingli",2200);
        set("eff_jingli",2200);
        set("jiali",100);   
	set("combat_exp", 800000);
       
       set_skill("staff", 160);
       set_skill("cuff", 160);
       set_skill("force",160);
       set_skill("dodge",160);
       set_skill("parry",160);
       set_skill("wushang-dali",180);
       set_skill("qingmang-jianfa", 180);
      
       map_skill("staff", "wushang-dali");
       map_skill("parry", "wushang-dali");
       map_skill("dodge", "qingmang-jianfa");

       setup();
       carry_object(ARMOR_D("cloth"))->wear();
       carry_object(BINGQI_D("gangzhang"))->wield();
       carry_object("/d/foshan/obj/yaoshi");
}

void init()
{	
	object ob; 
	ob = this_player();
	::init();
	if( interactive(ob)){
		remove_call_out("greeting");
		call_out("greeting", 1, ob);		
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
          this_object()->kill_ob(ob);        
}
