inherit NPC;

void create()
{
   set_name("��׵�", ({ "bai diao"}) );
   set("race", "Ұ��");
   set("age", 18);
   set("long", "�����ڴ��ԭ�е�һ�����ݡ�\n");
   
   set("str", 28);
   set("cor", 24);
   set("combat_exp",180000);
   set("env/wimpy",50);

   set("limbs", ({ "ͷ��", "����", "���", "�ҳ�", "���","�ҽ�" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_chance", 6);
   set("chat_msg", ({
  "��׵����Ʋ�������,˫���ӹ����ذ���.\n",
  "�Ʋ���һ����������,������ǰ����һ�����\n",

 }));


   setup();
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
         message_vision("��ͻȻ���ִ�׵�������߿գ������ֿ�ϧ�Լ�ȴû����˫��򣿡�\n", ob);
}