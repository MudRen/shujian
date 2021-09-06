// zhang.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�ŷ���", ({ "zhang furen", "zhang", "furen"}));
        set("long", "��Ů�Ӽ���΢�ƣ�˫�ۼ��󣬺�����ᡣ\n"+
		"���ƹ����½����置���������嶾�̡���ʹ���ַ��������أ����˷���ʤ����\n");
        set("gender", "Ů��");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);

        set("max_qi", 700);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 100000);
        set("shen", -1000);

        set_skill("tianmo-gong",100);
        set_skill("ding-dodge",100);
        set_skill("parry",100);        
        set_skill("force",100);
        set_skill("dodge",100);
        set_skill("tianshan-zhang", 100);
        set_skill("staff", 100);
        set_skill("strike", 100);
        set_skill("literate", 80);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmo-gong");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");
        setup();

	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();        
}
