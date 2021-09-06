//by jhkl@sd
//���pot��ν���˷�
//

inherit ROOM;

int deposit(string arg, object ob);
int check(string arg, object ob);
int withdraw(string arg, object ob);

void create ()
{
  set ("short", "Ǳ������");
  set ("long", @LONG

����һ�����齣��ʦ�����鿪���רΪ��Ҵ���Ǳ�ܵ����С�
�����ǳ��ĺã�ͯ�����ۣ���ȫ��Ҳֻ�д�һ�ң����޷ֺš�
��������һ����һ�������ʯ��̵���Ȼ����(pingfeng)��
���е��ſڹ���һ��ƽ���������(paizi)��

LONG);
  set("item_desc", ([
                "paizi": @TEXT
������Ǳ�����У�Ŀǰ�����ṩ�ķ����У�

qn_cha         ��Ǳ�ܡ�
qn_cun         ��Ǳ�ܡ�
qn_qu          ȡǱ�ܡ�

ע�⣺������һǧ��
��  ��������ȡ��ʱ���۵�0.1%��Ǳ�ܣ�
     
TEXT,
      "pingfeng": "�������ʯ�����ƺ������ƿ�(push)��\n",
      "����" : "�������ʯ�����ƺ������ƿ�(push)��\n",
      "����ʯ����" : "�������ʯ�����ƺ������ƿ�(push)��\n"
        ]) );      
  set("exits", ([ /* sizeof() == 4 */
  "down" : "/d/xiangyang/zahuopu",
  
]));
  set("no_fight", 1);
  setup();

}

void init()
{
   add_action("do_deposit", "qn_cun");
   add_action("do_check", "qn_cha");
   add_action("do_withdraw", "qn_qu");
   add_action("do_push", "push");
   
}

int do_deposit(string arg, object ob)
{
       int amount;
       object me,who;
       me = this_player();
       who = this_object();
   
   if(!arg || sscanf(arg, "%d", amount) !=1)
   {
     return notify_fail("�����ʽ��qn_cun <����>\n");
   } 

         if(((int)me->query("potential")-(int)me->query("learned_points")) < amount)
        {
                return notify_fail("��û����ô��Ǳ�ܡ�\n");
        }
         
        if(amount<0)          {
                object *objs = all_inventory(me);
                int i = sizeof (objs);
                message_vision ("$N����븺Ǳ�ܣ�grin...\n �����ͻȻ�ɳ�һ�����ӣ���$N�ĺ��Ժݺ�������ȥ��\n",me);
                me->unconcious();   
                while (i--) 
                 {
                    object obj = objs[i];
                    message_vision ("$N���ϵ�"+obj->query("name")+"Ī������ķ����ˡ�\n",me);
                    obj->move(me);
                    destruct(obj);
                 }
                return 1;
        } 
        
  
        message_vision(sprintf("$N�ó�%s��Ǳ�ܣ���������С�\n",
           chinese_number(amount)), me);
        me->add("qn_balance",amount);
        me->add("potential",-amount);

        me->save();

   return 1;
}

int do_check()
{
   int total = (int)this_player()->query("qn_balance");

   if(!total || total < 0)  {
        this_player()->set("qn_balance", 0);
   return notify_fail("����������û�����Ǳ�ܡ�\n");
   }
   write("���ڱ����й�����" +
         chinese_number(total) + "��Ǳ�ܡ�\n");
   return 1;
}

int do_withdraw(string arg)
{
   int amount, v, sl,rv;
   object me;

   me = this_player();
   sl = me->query("daoluan");

        if (!arg || sscanf(arg, "%d", amount) != 1)
        {
                return notify_fail("�����ʽ��qn_qu <����>\n");
        }

        if (amount < 1)
        {
                return notify_fail("����ȡ������Ǳ�ܣ�\n");
        }
 
        if ((v = amount) > me->query("qn_balance"))
        {
                return notify_fail("����Ǳ�ܲ���ȡ��\n");
        }
  
        rv = v;

        if(sl<1)
        {
            if(v<1000)
              {
                v=v-1;
                me->add("qn_balance",  -rv);
                me->add("potential",v);
                me->save();
                message_vision(sprintf("$N��������ȡ��%s��Ǳ�ܡ�\n", chinese_number(v)),me);
               }                
             else
              { 
                sl=1;
                v = v-v*sl/1000; 
                me->add("qn_balance",  -rv);
                me->add("potential",v);
                me->save();
                message_vision(sprintf("$N��������ȡ��%s��Ǳ�ܡ�\n", chinese_number(v)),me);
               } 
          }
 
         if(sl>1)
         {
             if(v<1000)
             {
                v=v-sl; 
                me->add("qn_balance",  -rv);
                me->add("potential",v);
                me->save();
                message_vision(sprintf("��Ϊ$N���⵷�ҹ�%d��,����$N��˰����ǧ��֮%s.\n",sl,chinese_number(sl)),me);
                message_vision(sprintf("$N��������ȡ��%s��Ǳ�ܡ�\n", chinese_number(v)),me);
              } 
              else
              { 
                v = v-v*sl/1000; 
                me->add("qn_balance",  -rv);
                me->add("potential",v);
                me->save();
                message_vision(sprintf("��Ϊ$N���⵷�ҹ�%d��,����$N��˰����ǧ��֮%s.\n",sl,chinese_number(sl)),me);
                message_vision(sprintf("$N��������ȡ��%s��Ǳ�ܡ�\n", chinese_number(v)),me);
               }
          }
    return 1;
}


void close_path()
{
        if( !query("exits/north") ) return;
        message("vision",
"����ʯ�������ƻ���ԭλ����ס�˰��š�\n",
                this_object() );
                delete("exits/south");
}


int do_push(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;

        if( arg=="pingfeng" || arg =="����" || arg=="����ʯ����") {
                write("���ƿ�����ʯ���磬");
        if( (int) me->query("force_factor") >= 150 )
                {
                write("�ƿ��˺������ϵ�һ�Ȱ��š�\n");
                if( !query("exits/west") ) {
                set("exits/south", __DIR__"neishi");
                call_out("close_path", 5);
                                                }
                return 1;       
                }
                else
                write("���������ƺ���İ��ţ���û���ƿ���\n");
                return 1;
        }
                write("��Ҫ�ƿ�ʲô��\n");
}


