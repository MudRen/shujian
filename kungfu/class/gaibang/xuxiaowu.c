// xuxiaowu.c ��С��

inherit NPC;

void create()
{
        set_name("��С��", ({ "xu xiaowu", "xu", "xiaoxu" }));
        set("title","ؤ���Ĵ�����");
        set("long","����һ��ؤ����ӡ�\n");

        set("gender", "����");
        set("age", random(20)+30);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 18+random(5));
        set("int", 14+random(5));
        set("con", 20+random(5));
        set("dex", 22+random(5));

        set("max_qi", 2000+random(500));
        set("max_jing", 2000+random(200));
        set("neili", 3500+random(500));
        set("max_neili", 3000+random(500));
        set("max_jingli",2000+random(500));
        set("eff_jingli",2500+random(500));
        set("jiali", 100);
        set("combat_exp", 800000+random(200000));

        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("xianglong-zhang", 150);
        set_skill("xiaoyaoyou", 150);
        set_skill("huntian-qigong", 150);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong-zhang");
        prepare_skill("strike", "xianglong-zhang");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "strike.xiao" :),
                (: exert_function, "huntian" :),
                (: perform_action, "strike.paiyun" :),
                (: perform_action, "strike.kanglong" :),
        }));
        create_family("ؤ��", 19, "�Ĵ�����");
        set("inquiry", ([
                "ؤ��" : "����ؤ�������µ�һ��\n",
                "�Ƿ�" : "�ǰ����Ǹ��ú��ӡ�\n",
                "����" : "�������ǵ�ǰ�ΰ�����\n",
        ]));
        setup();
        carry_object(CLASS_D("gaibang/obj/gb_budai4"))->wear();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
