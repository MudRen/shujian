// NPC :gan_baobao.c �ʱ��� 
// By River 98/12
inherit NPC;
void create()
{
        set_name("�ʱ���", ({ "gan baobao", "gan", "baobao"}));
        set("title","��ٹȹ�������");
        set("nickname","��ҹ��");        
        set("gender", "Ů��" );
        set("age", 36);
        set("str", 17);
        set("con", 23);
        set("dex", 26);
        set("int", 25);
        set("per", 25);
   	set("attitude", "friendly");

        set("max_qi", 1000);
        set("max_jing", 800);
        set("eff_jingli", 800);
        set("neili", 1000);
	set("qi", 1000);	
        set("max_neili", 1000);      
        set("unique", 1);
        
        set("long","�⸾��ԼĪ��ʮ������������ͣ���ɫ���㣬üĿ����ϡ�������������ơ�\n");
        set("combat_exp", 200000);
        set("shen", 800); 

        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("strike", 80);
        set_skill("qiantian-yiyang", 80);        
        set_skill("tianlong-xiang", 80);
        set_skill("zhongjia-zhang", 80);
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "zhongjia-zhang");
        map_skill("strike", "zhongjia-zhang");
        map_skill("force", "qiantian-yiyang");
        prepare_skill("strike","zhongjia-zhang");

        set("inquiry", ([            
//            "������" : (: ask_duan :),
        ]));

        setup();
        carry_object(__DIR__"obj/lvshan")->wear();
}
