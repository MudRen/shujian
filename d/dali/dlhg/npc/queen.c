#include <ansi.h>
inherit NPC;

int mu();
string yuzhuo();

void create()
{
set_name("�����ʺ�", ({ "zhenggong huanghou", "zhenggong" ,"huanghou"}));
        set("title", "�������");
set("gender", "Ů��");
set("age", 35);
set("per", 29);
        set("unique", 1);
set("count", 1);
set("combat_exp", 5000);
        set("attitude", "friendly");
        set("rank_info/respect", "����");
set("long", 
        "�����Ǵ�����Ļʺ󣬿���ȥ����Ӻ�ݣ������ͻۣ�һ���Ͱ����׵����ӡ�\n");
set("inquiry", ([
//"ľ����" : (: mu :), 
//"����" : (: yuzhuo :),
]) );
setup();
carry_object(__DIR__"obj/fengpao")->wear();
}

void kill_ob(object ob)
{
        command("say �㲻Ҫ��ڣ�����һ����Ϊ�ұ���ģ�����");
        ob->set_temp("killqueen",1);
}

int mu()
{
       command("ah");
       command("say ��λ" + RANK_D->query_respect(this_player()) + "ԭ����ľ��������ѣ�ʧ����ʧ����");
//       this_player()->set_temp("mu",1);
       return 1;
}

string yuzhuo()
{
object ob;
ob = unew(__DIR__"obj/yuzhuo");
if (!this_player()->query_temp("mu"))
   return RANK_D->query_respect(this_player())+"�밧����ζƽ������֪�˻��Ӻ�̸��";
        if(!clonep(ob))
           return "���Ѱ��������ľ�����ˡ�";
         ob->set_temp("give_player", this_player()->query("id"));
 ob->move(this_player());         
         this_player()->delete_temp("mu");
           return "��" + RANK_D->query_respect(this_player()) + "����ֻ�������ľ����ɡ�";
}
