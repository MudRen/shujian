inherit F_CLEAN_UP;

int main(object me, string arg)
{
   object ob;

   if( me != this_player(1) ) return 0;

   ob = me->query_temp("link_ob");
   if( !ob ) return 0;
   while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

   write("Ϊ�˽��װ�ȫ���������������ԭ����PIN�룺");
   input_to("get_old_pass", 1, ob);
   return 1;
}

private void get_old_pass(string pass, object ob)
{
   string old_pass;

   write("\n");
   old_pass = ob->query("security-code");
   if(!old_pass)
    write("����δ�趨PIN�룡\n");


   else if( crypt(pass, old_pass)!=old_pass ) {
     write("PIN�����\n");
     return;
   }
   write("�������µ�PIN�룺");
   input_to("get_new_pass", 1, ob );
}

private void get_new_pass(string pass, object ob)
{
   write("\n��������һ���µ�PIN�룺");
   input_to("confirm_new_pass", 1, ob, crypt(pass,0));
}

private void confirm_new_pass(string pass, object ob, string new_pass)
{
   write("\n");
   if( crypt(pass, new_pass)!=new_pass ) {
     write("�Բ����������PIN�벢����ͬ������ʹ��ԭ����PIN�롣\n");
     return;
   }
   seteuid(getuid());
   if( !ob->set("security-code", new_pass) ) {
     write("PIN����ʧ�ܣ�\n");
     return;
   }

   ob->save();
   write("PIN�����ɹ���\n");
}

int help(object me)
{
   write(@HELP
ָ���ʽ : pin
 
���ָ������޸���İ�ȫ����PIN���롣
 
HELP
    );
    return 1;
}
 