#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"����"NOR, ({ "nian shou", "nian", "shou" }) );
        set("race", "Ұ��");
        set("age", 4);
       set("unique", 4);
        set("long", "����ʨ�Ӷ����ǣ���ʱ�����˺��������ǿ����Ʒ�֮����\n");
        set("attitude", "peace");
        set("shen_type", -1);
        
set("str", 20);
    set("int", 20);
    set("con", 20);
    set("dex", 20);
        set("kar", 100);
        set("pur", 100);
    set("jingli",600000);
set("qi",500000);
set("max_qi",500000);
    set("max_jing", 500000);
    set("eff_jingli", 600000);
    set("jiali", 190);
        set("limbs", ({ "����ͷ", "������", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 10000);

set_temp("apply/attack", 10);
set_temp("apply/defense", 10+ random(200));
set_temp("apply/armor", 10+ random(200));

set_skill("force", 40 + random(50));
set_skill("dodge", 30 + random(50));
set_skill("parry", 30 + random(50));
set_skill("literate", 50 + random(50));
set_skill("cuff", 40 + random(50));
        setup();

        set("chat_chance", 30);
        set("chat_msg", ({
                "����ҡͷ��β�ſ���ڣ�����Ҫ���ˡ�\n",
                "���޵���ͭ���Ĵ������´������㹻����һ�ٷ��ġ�\n",
(: random_move :)
        }) );
}

int accept_fight(object ob)
{
        command("say ��໣���Ҫɱ��ɱ���Ҳ������fight��");
        return 0;
}
void unconcious()
{
object ob;
object me; 
me = query_temp("last_damage_from");
 if ( random(100) > 95 && random(100) < 100 )
          {
  ob = new("clone/spec/yuji");
            ob->move(me);
           command("rumor ��˵"+ me->name(1)+ "�ڷ���ɱ���޻ʱ����õ�"+ ob->name(1)+ "��");  
          die();
       } 
 if ( random(100) > 85 && random(100) < 90 )
          {
  ob = new("clone/spec/dahuandan");
            ob->move(me);
           command("rumor ��˵"+ me->name(1)+ "�ڷ���ɱ���޻ʱ����õ�"+ ob->name(1)+ "��");  
          die();
       } 
   else 
{
ob = new("u/hongba/dengmi");
   ob->move(me); 
command("rumor ��˵"+ me->name(1)+ "�ڷ���ɱ���޻ʱ����õ�"+ ob->name(1)+ "��");  
          die();
       } 
}