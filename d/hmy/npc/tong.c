// Finish by Numa@SJ 2000.8

#include <ansi.h>
inherit F_MASTER;
inherit NPC;

void create()
{
        set_name("ͯ����", ({ "tong baixiong", "tong", "baixiong"}));
        set("long", "һ���뷨��׵����ߣ���Ŀ��࣬˫Ŀ��������\n"+
        	"���ƹ������½̷����ã������Ž������ж��������\n");
        set("title",HIY"������� "HIC"��������"NOR);
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 38);

        set("max_qi", 3500);
        set("max_jing", 2200);
        set("eff_jingli", 2200);
        set("jiali", 100);
        set("combat_exp", 1800000);
        set("shen", -1);

        set_skill("parry", 210);
        set_skill("dodge", 210);
        set_skill("force", 210);
        set_skill("blade", 210);
        set_skill("ding-dodge", 210);
        set_skill("tianmo-dao", 210);
        set_skill("tianmo-gong", 210);
        set_skill("strike", 210);
        set_skill("luoying-zhang", 210);
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmo-gong");
        map_skill("blade", "tianmo-dao");
        map_skill("parry", "luoying-zhang");
        map_skill("strike", "luoying-zhang");
        prepare_skill("strike", "luoying-zhang");
        create_family("�������",8,"����");

        
        set("inquiry", ([
        ]));
        
        setup();
 
        carry_object(MISC_D("cloth"))->wear();
}





