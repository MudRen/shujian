// /d/xiangyang/npc/lvwende.c
// by looklove 2000/8/23
inherit NPC;
string ask_me();
void create()
{
        set_name("���ĵ�", ({ "lv wende", "lv" }));
        set("title", "����֪��");
        set("gender", "����");
        set("age", 40);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("long", "��������������֪����������������ξ������ɹ����ӶԿ���\n");
        set("combat_exp", 350000);
        set("attitude", "peaceful");
       set("max_qi", 1200);
       set("max_jing", 1200);
       set("eff_jingli", 1000);
       set("jiali", 30);
       set_skill("force", 70); 
       set_skill("unarmed", 80);
       set_skill("strike", 70);
       set_skill("sword", 70);
       set_skill("dodge", 70);
       set_skill("parry", 70);
       set_skill("qingmang-jianfa", 80); 
       map_skill("sword", "qingmang-jianfa");
       map_skill("parry", "qingmang-jianfa");
       map_skill("parry", "qingmang-jianfa");
       set("inquiry", ([              
                "����Ͷ��" : (: ask_me :),
                "Ͷ��" : (: ask_me :),
       ]));
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

void kill_ob(object ob)
{
//        ob->remove_killer(this_object());
//        remove_killer(ob);
        command("say ɱ��������������");
        ob->add_condition("killer", 5);
        ::kill_ob(ob);
}

int accept_object(object me, object obj, object ob)
{            
        int i = me->query("combat_exp")/20000;
        ob = this_object();

i *= 10000;
if (i < 200000) i = 200000;

if(obj->query("money_id")){
 if(me->query("menggu") && me->query_temp("money_ask")){
  if(obj->value() >= i){
              command("haha " + me->query("id"));
              command("whisper "+me->query("id")+" ��ͷ��İɣ�����°��������ϣ�");
                me->delete("menggu");
                me->delete_temp("money_ask");
              return 1;
              }
          else {
              command("say ����ô��Ǯ�ܸ�ʲô��");
              return 1;
              }
          }
        else {
             command("say ����ô��Ǯ�ܸ�ʲô��");
             return 1;
             }
}
    
if(userp(obj))
        return 0;
        if(obj->query("id") == "renshen guoo") return 0;//����rsg
        if(obj->query("treasure"))
        {
           command("thumb " + me->query("id"));
           command("touch " + me->query("id"));
           tell_object(me,"���ĵ¶����޵���ֵ������Σ��֮��"+RANK_D->query_respect(me)+"�״����䣬��������֮ʿҲ��\n");
            if (obj->query("value")>2000)
            {
            me->add("shen", (obj->query("value")/20));
            }
            else 
            me->add("shen", (obj->query("value") * 5));
            call_out("destroy", 1, obj);
            return 1;
        }
        else
        {
        command("hmm " + me->query("id"));
command("say �Ҷ�"+obj->name()+"��ϡ����");
//             call_out("destroy", 1, obj);
}
return 1;
}

string ask_me()
{
object me = this_player();
        int i = me->query("combat_exp")/20000;
    
    if(!me->query("menggu")) return "�Ķ����İ������ң�";
        if (i < 20) i = 20;
    me->set_temp("money_ask", 1);
    message_vision("\n$N����$n������Ц����Ͷ���Ҵ������ǰɣ�\n", this_object(), me);
    command("whisper "+me->query("id")+" "+chinese_number(i)+"���ƽ�");
    return "��֪������ͷ���ɹ��˵�̬�ȡ�����Ҳ�������������ɣ�\n";
}

void destroy(object obj)
{
destruct(obj);
}
