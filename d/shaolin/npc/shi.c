// shi.c ʷ��ɽ

inherit NPC;

void create()
{
       set_name("ʷ��ɽ", ({ "shi qingshan", "shi" }));
       set("title", "�����ؽ�");
       set("gender", "����");
       set("age", 33);
       set("str", 25);
       set("dex", 16);
       set("long", "ʷ��ɽ������ؤ���ʷ������С�ܣ���֪Ϊ�γ����˳�͢����\n");
       set("combat_exp", 200000);
       set("shen_type", 1);
       set("attitude", "heroism");

       set_skill("unarmed", 100);
       set_skill("force", 100);
       set_skill("sword", 100);
       set_skill("dodge", 100);
       set_skill("parry", 100);
       set_skill("stick", 100);
       set_skill("dagou-bang", 80);
       map_skill("parry", "dagou-bang");
       map_skill("stick", "dagou-bang");
       set_temp("apply/attack", 70);
       set_temp("apply/defense", 70);
       set_temp("apply/armor", 70);
       set_temp("apply/damage", 70);

       set("max_qi", 1700);
       set("qi", 1700);
       set("neili", 2000); 
       set("max_neili", 2000);
       set("jiali", 30);

       setup();
       carry_object("/clone/weapon/langya-bang")->wield();
//         carry_object(__DIR__"obj/tiejia")->wear();
}

int accept_fight(object me)
{
       command("say �Ϸ��δ�ͽ����˶��ֹ����ˣ�����Ҳ����������");
       return 0;
}
