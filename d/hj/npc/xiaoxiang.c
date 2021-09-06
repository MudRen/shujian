#include <ansi.h>

inherit NPC;

void create()
{
        object weapon;
        set_name("������", ({ "xiaoxiang zi", "zi", "xiaoxiang" }));
        set("title", "��������");
        set("long", "����ĸ��ݣ�����Ѫɫ��������ʬ����������͸��һ���������ֳ�һ����ɥ����\n");
        set("gender", "����");
        set("rank_info/respect", "����");

        set("age", 43);
        set("attitude","heroism");
        set("unique", 1);
        set("str", 26);
        set("dex", 20);
        set("con", 23);
        set("int", 22);
        set("shen", -7000);
        set("env/wimpy", 60);
        
        set_skill("parry", 160);
        set_skill("force", 160);
        set_skill("dodge", 160);
        set_skill("stick", 100);
        set_skill("huntian-qigong", 120);       
        set_skill("wushang-dali", 120);  
        set_skill("xiaoyaoyou", 120);
        set_skill("suohou-shou", 120);
        set_skill("hand", 100);
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("hand", "suohou-shou");
        map_skill("stick", "wushang-dali");
        prepare_skill("hand", "suohou-shou");
        
        set("combat_exp", 700000);
        set("max_qi", 1500);
        set("max_jing", 1000);
        set("eff_jingli", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        
        set("inquiry", ([            
            "���ַ���" : "�ٺ٣��ҳ������Ǹ��Ϻ��еĹ�ʦ������������",
            "�����" : "���Ǹ�ç��������ʲ��",
            "������" : "���˹��򲻴���������Ľ���̫ҫ�ۣ������������ʿ��",
            "��Ħ��" : "�������ģ��ڹ��������ǣ��ٺ٣�����̫С��",            
        ]));
        setup();
        set("chat_chance", 3);
        set("chat_msg", ({
            "�������۾�����б������Ǳ�΢΢��Ц��\n",
            (: random_move :),  
            "�����ӵ����������书�������ã��ѵ����ϵ�����������֮���᣿�ֵܿ��е㲻�������� ����\n", 
            (: random_move :),          
        }));
        
        if (clonep()){
           weapon = unew(BINGQI_D("kusang-bang"));
           if(!weapon) weapon=new(BINGQI_D("langya-bang")); 
              weapon->move(this_object());
              weapon->wield();
        }
        carry_object("/d/wudang/obj/greenrobe")->wear();
}

void kill_ob(object me)
{
      object ob=this_object();
      command("grin");
      command("say ���������ɣ�");
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);            
      ::kill_ob(me);
}
