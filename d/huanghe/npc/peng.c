// peng.c

inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("������", ({ "peng lianhu", "peng", "lianhu" }));
        set("gender", "����");
        set("nickname", HIR"ǧ������"NOR);
        set("age", 43);
        set("str", 25);
        set("dex", 16);
        set("per", 20);
        set("long", "�����������ģ����ۺ�˿��Ŀ����磬�ϴ���������������
�б�����ɳͨ�������Ľ��顣\n");
        set("combat_exp", 200000);
        set("shen_type", -1);
        set("attitude", "peaceful");

        set("max_qi", 1100);
        set("max_jing", 800);
        set("neili", 1400);
        set("max_neili", 1400);
        set("jiali", 50);
        set("combat_exp", 600000);
        set("shen", -6000);

    set_skill("force", 100);
    set_skill("hunyuan-yiqi", 120);
    set_skill("dodge", 100);

    set_skill("shaolin-shenfa", 120);
    set_skill("hand", 100);
    set_skill("weituo-zhang", 120);
    set_skill("parry", 100);
    set_skill("staff", 100);
    set_skill("qianye-shou", 120);
    set_skill("literate", 50);

    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shnfa");
    map_skill("hand", "qianye-shou");
    map_skill("parry", "weituo-zhang");
    map_skill("staff", "weituo-zhang");
    prepare_skill("hand", "qianye-shou");

         set("inquiry", ([
                "����" : "�ٺ�, ��������������Ϣ��",
                "����Ƽ" : "�ǿ��Ǹ����˰���",
                "ɳͨ��" : "���ҵĽ���ֵܣ�",
                "��ͨ��" : "Ҳ���ҵ��ֵܰ���",
                "Ǯ�ཡ" : "����������ʲ�᣿",
        ]) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangzhang")->wield();
        add_money("silver", 30);
}
