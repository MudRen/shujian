// lan.c

#include <ansi.h>
inherit F_MASTER;
inherit NPC;

void create()
{
        set_name("�����", ({ "lan fenghuang", "lan", "fenghuang"}));
        set("long", "��Ů�Ӽ���΢�ƣ�˫�ۼ��󣬺�����ᡣ\n"+
        	    "���ƹ����½����置���������嶾�̡���ʹ���ַ��������أ����˷���ʤ����\n");
        set("title",HIY"�������  "HIR"�嶾ʥ��"NOR);
        set("gender", "Ů��");
        set("age", 23);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("per", 25);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);

        set("max_qi", 2800);
        set("max_jing", 1600);
        set("eff_jingli", 1600);
        set("jiali", 50);
        set("combat_exp", 1500000);

        set_skill("parry", 180);
        set_skill("poison", 180);
        set_skill("dodge", 180);
        set_skill("force", 180);
        set_skill("strike", 180);
        set_skill("literate", 100);
        set_skill("ding-dodge", 180);        
        set_skill("huntian-qigong", 180);
        set_skill("zhusha-zhang", 180);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "huntian-qigong");
        map_skill("parry", "zhusha-zhang");
        map_skill("strike", "zhusha-zhang");
        prepare_skill("strike", "zhusha-zhang");
        
	      create_family("�������",9,"����");
       	setup();
	carry_object(MISC_D("cloth"))->wear();        
}
