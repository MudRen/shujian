// NPC :zhong_ling.c ���� 
// By River 98/12
inherit NPC;
void create()
{
        set_name("����", ({ "zhong ling", "zhong", "ling"}));
        set("title","��ٹȹ���Ů��");        
        set("gender", "Ů��" );
        set("age", 16);
        set("str", 17);
        set("con", 23);
        set("dex", 26);
        set("int", 25);
        set("per", 25);
   	set("attitude", "friendly");

        set("max_qi", 800);
        set("max_jing", 600);
        set("eff_jingli", 600);
        set("neili", 800);
	set("qi", 800);	
        set("max_neili", 800);      
        set("unique", 1);
        
        set("long","����ŮԼĪʮ��������ͣ�һ��������Ц���绨��\n");
        set("combat_exp", 100000);
        set("shen", 500); 

        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("force", 60);
        set_skill("strike", 60);
        set_skill("qiantian-yiyang", 60);        
        set_skill("tianlong-xiang", 60);
        set_skill("zhongjia-zhang", 60);
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "zhongjia-zhang");
        map_skill("strike", "zhongjia-zhang");
        map_skill("force", "qiantian-yiyang");
        prepare_skill("strike","zhongjia-zhang");

        set("inquiry", ([            
//            "������" : (: ask_duan :),
        ]));

        setup();
        carry_object(__DIR__"obj/qingshan")->wear();
}
