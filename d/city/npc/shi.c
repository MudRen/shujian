// shi.c ʷ��ɽ
#include <ansi.h>
inherit NPC;
string ask_me();
void create()
{
       set_name("ʷ��ɽ", ({ "shi qingshan", "shi" }));
       set("title", "�����ؽ�");
       set("gender", "����");
       set("age", 33);
       set("str", 25);
       set("dex", 16);
   set("long", "ʷ��ɽ�������䵱ɽ���׼ҵ��ӣ��ָ�ؤ���е������ֻ�ǲ�֪Ϊ�γ����˳�͢����\n");
       set("combat_exp", 200000);
       set("shen_type", 1);
       set("attitude", "heroism");

       set_skill("unarmed", 100);
set_skill("tiyunzong",100);
set_skill("yinyun-ziqi",100);
       set_skill("force", 100);
       set_skill("sword", 100);
       set_skill("dodge", 100);
       set_skill("parry", 100);
       set_skill("stick", 100);
       set_skill("dagou-bang", 100);
       map_skill("parry", "dagou-bang");
       map_skill("stick", "dagou-bang");
map_skill("dodge","tiyunzong");
       set_temp("apply/attack", 70);
       set_temp("apply/defense", 70);
       set_temp("apply/armor", 70);
       set_temp("apply/damage", 70);

        set("inquiry", ([
              
                "Ϊ��" : (: ask_me :),
                "��Ч��͢" : (: ask_me :),
       ]));
       
       set("max_qi", 1700);
       set("qi", 1700);
       set("neili", 2000); 
       set("max_neili", 2000);
       set("jiali", 30);

       setup();
       carry_object("/clone/weapon/langya-bang")->wield();
       carry_object(__DIR__"obj/tiejia")->wear();
}

int accept_fight(object me)
{
       command("say �Ϸ��δ�ͽ����˶��ֹ����ˣ�����Ҳ����������");
       return 0;
}

void init()
{
       object ob;
       ::init();
       if (interactive(ob = this_player()) && living(this_object()) &&
               (int)ob->query_condition("killer")) {
               remove_call_out("kill_ob");
               call_out("kill_ob", 0, ob);
       }
}

string ask_me()
{        
       object ob, me;
       int gftimes;

       me = this_player();
       ob = this_player();
       gftimes = (int)ob->query("gf_job",1);
       
       if (gftimes<1)
       return "��λ"+RANK_D->query_respect(me)+"��û��Ϊ��͢����������̸�����أ���\n"; 
       if (gftimes>=1 && gftimes<50)
       return "��λ"+RANK_D->query_respect(me)+"Ŀǰ���Ͳ���������Ŭ���ɣ���\n"; 
       if (gftimes>=50 && gftimes<100){
       command("nod ");
       command("say ���ѽ���Ĺ��ͱ����˱������飬ǰ�ձ�������������Ϊ�첶��");
       me->set_temp("apply/short", ({HIY"��͢��Ա��Ʒ�첶 "NOR+me->name()+"("+me->query("id")+")"}));
       return "�ұ������������Ϊ���ҳ�����Ϊ�����츣����\n"; 
       }
       if (gftimes>=100 && gftimes<200){
       command("nod " + me->query("id"));
       command("say ���ѽ���Ĺ��ͱ����˱������飬ǰ�ձ�������������Ϊ��ͷ��");
       me->set_temp("apply/short", ({HIY"��͢��Ա��Ʒ��ͷ "NOR+me->name()+"("+me->query("id")+")"}));
       return "�úøɣ��Ϸ��ǲ��������ģ�\n";
       }
       if (gftimes>=200 && gftimes<500){
       command("pat " + me->query("id"));
       command("say ��λ"+RANK_D->query_respect(me)+"�Ĺ������Դ��ߴ��С��ش�������Ϊ������");
       me->set_temp("apply/short", ({HIY"��͢��Ա��Ʒ���� "NOR+me->name()+"("+me->query("id")+")"}));
       return "��λ"+RANK_D->query_respect(me)+"�Ĺ��Ͳ�С���Ϸ��´ν�����һ��Ҫ��������������飡\n";
       }
       if (gftimes>=500 && gftimes<1000){
       command("thumb " + me->query("id"));
       me->set_temp("apply/short", ({HIY"��͢��Ա��Ʒ��˾ "NOR+me->name()+"("+me->query("id")+")"}));
       return "��λ"+RANK_D->query_respect(me)+"�ĳɼ���С������Ҫ�ͽ������˴�Ļ��ȣ������ݹ��Ϸ��������飡\n";
       }
       if (gftimes>=500 && gftimes<1000){
       command("haha " + me->query("id"));
       command("say ��λ"+RANK_D->query_respect(me)+"���书���Ǿ�Ϊ������һ������Ŭ���ɣ�");
       me->set_temp("apply/short", ({HIY"��͢��Ա��Ʒ�λ� "NOR+me->name()+"("+me->query("id")+")"}));
       return "��˵������ϳ��н�������û����ȥ��鿴��\n";
       }
       if (gftimes>=1000 && gftimes<2000){
       me->set_temp("apply/short", ({HIY"��͢��Ա��Ʒ�ν� "NOR+me->name()+"("+me->query("id")+")"}));
       return "�Ϸ��Ѱ�����Ϊ�ν����Ժ�����»ָ�տɴ���\n";
       }
       if (gftimes>=2000 && gftimes<2500){
       me->set_temp("apply/short", ({HIY"��͢��Ա����Ʒ���� "NOR+me->name()+"("+me->query("id")+")"}));
       return "��˵����������Ҫ����ǰȥ���ǣ����Ժ�ǰ;Զ�󰡣�\n";
       }
       if (gftimes>=2500 && gftimes<3000){
       me->set_temp("apply/short", ({HIY"��͢������Ʒ�ܱ� "NOR+me->name()+"("+me->query("id")+")"}));
       return "��˵����������Ҫ����ǰȥ���ǣ����Ժ�ǰ;Զ�󰡣�\n";
       }
       if (gftimes>=3000 && gftimes<3500){
       me->set_temp("apply/short", ({HIY"��͢�س���һƷ�ᶽ "NOR+me->name()+"("+me->query("id")+")"}));
       return "��˵����������Ҫ����ǰȥ���ǣ����Ժ�ǰ;Զ�󰡣�\n";
       }
         if (gftimes>=3500 && gftimes<4500){
        me->set_temp("apply/short", ({HIY"��͢�س���һƷ�󽫾� "NOR+me->name()+"("+me->query("id")+")"}));
       return "��˵����������Ҫ����ǰȥ���ǣ����Ժ�ǰ;Զ�󰡣�\n";
        }
       if (gftimes>4500){
       me->set_temp("apply/short", ({HIY"��͢�ղ�� "NOR+me->name()+"("+me->query("id")+")"})); //wiz get it now
       return "���ᣬ����ѹ����ı��Ϸ򻹴�\n";
       }
}

void die()
{
        object killer;
        if(objectp(killer = query_temp("last_damage_from")) ){
                killer->apply_condition("killer", killer->query_condition("killer")+100);
                command("say "+killer->name()+"�㾹��ıɱ��͢���٣����˰�������");
                }
        ::die();
}       

