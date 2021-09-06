// penglianhu.c ������

inherit NPC;
 
void create()
{
        set_name("������", ({ "peng lianhu", "peng", "lianhu" }));
        set("nickname", "ǧ������");
        set("long", 
        "������ɱ�˲���գ�۵Ĵ��ǧ��������������\n"
        "һ��һ��а��������ʮ�ֽƻ��ļһ\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("str", 29);
        set("int", 20);
        set("con", 25);
        set("dex", 23);
        
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
           add_money("gold",2);
}
