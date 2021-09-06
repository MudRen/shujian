void init()
{
       call_out("destruct", 30, this_object());        
       add_action("do_tu", "tu");
}

int do_tu(string arg)
{
       string me, what;
       mapping fam; 
       object ob;
       int i;

       if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
       return notify_fail("���ֲ������޵��ӣ��������������յ�������");

       if( this_player()->is_busy() )   return notify_fail("����æ���أ�\n");
       i = (this_player()->query_skill("poison")/10)+3;
      
       if( !arg
       ||      sscanf(arg, "%s on %s", me, what)!=2
       ||      !id(me) )
               return notify_fail("�����ʽ: tu <ҩ> on <����>��\n");

       ob = present(what, this_player());
       if( !ob )
               return notify_fail("������û��" + what + "����������\n");
       if( !ob->query("weapon_prop") )
               return notify_fail("ֻ��Ϳ�������ϡ�\n");
               
       
       ob->set("poisoned", query("poison"));
       ob->set("poison_number", ob->query("poison_number")+i);

       ob->set_temp("apply/long", ({ob->query("long")+"������ȥ"+query("drug_color")+"�������Ǳ�ι�˾綾��\n"}));
       message_vision("$N������ȥ����$n����"+query("name")+"������Ѭ����\n", this_player(),ob);
       this_player()->start_busy(2);
       add_amount(-1);
       return 1;
}

void destruct(object ob)
{
   message_vision("$N������ȼ�����ˡ�\n",ob);
   ob->add_amount(-1);
   return;
}   