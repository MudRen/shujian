
#include <net/socket.h>
#include <ansi.h>
#define SITE "202.106.184.193"
inherit F_DBASE;
int have_get=0;
int fail=0;
string msg="";
int check_time();
void close(int);
void write_s(int);
void create()
{
set("channel_id","����Ԥ��");
seteuid(getuid());
check_time();
}
int check_time()
{
mixed* times=localtime(time());
int hours=times[2];
int fd,fc;
if(! have_get)//ÿ��3�㿪ʼץ��ҳ
{
 if(fd=socket_create(STREAM,"read_callback")<0)
        {
                write("socket_create error "+fd+"\n");
                return 1;
        }
        if((fc=socket_connect(fd,SITE+" 80","read_callback","write_callback"))!= EESUCCESS)
        {
         close(fd);
                write("socket_connect error "+fc+"\n");
                return 1;
        }
        remove_call_out("write_s");
        call_out("write_s",2,fd);
        remove_call_out("close");
        call_out("close",20,fd);//�ȴ���ʮ�룬��ʱ��Ϊ����ʧ�ܡ�
}
if(hours==12)
{
 have_get=0;//12��������
 msg="";
 fail=0;
}
remove_call_out("check_time");
call_out("check_time",10);
return 1;
}
void read_callback(int fd,mixed val)
{
       msg+=sprintf("%O",val);
}
void write_callback(int fd)
{
       return;
}
void close(int fd)
{
string sun;
       string gaowen;
       string diwen;
       string fengli;
       write("close start\n");
if(strsrch(msg,"HTTP/1.1 200 OK")!=-1) //�ɹ���ȡ
       {
        //��Щ�ַ��������������ҳ��ء�
        int index,index2;
        string* msgArray=({});
        index=strsrch(msg,"����");
        msg=msg[index..sizeof(msg)];
        index2=strsrch(msg,"</tr>");
        msg=msg[0..index2-1];
        msg=replace_string(msg,"/","");
        msgArray=explode(msg,"<td>");
        msgArray=filter_array(msgArray,(:$1!="\r\n ":));
   if(sizeof(msgArray)!=7)
   {
    write("size:"+sizeof(msgArray)+"\n");
    for(int i=0;i<sizeof(msgArray);i++)
    {
     write(msgArray[i]);
    }
    write("��ʽ����\n");
   }
        else
        {
         sun=msgArray[1];
         fengli=msgArray[2];
         diwen=msgArray[3];
         gaowen=msgArray[6];
   write_file("/adm/etc/weather.log","\n\t\t\t���ձ���������"+HIB+sun+NOR+"
\n\t\t\t�������:"+HIR+diwen+NOR+"\n\t\t\t�������:"+HIY+gaowen+NOR+"\n",1);

   write("OK!\n");
  }
       }
else
{
 write("��ȡ����\n");
}
       socket_close(fd);
}
void write_s(int fd)
{
       int fw;
       if((fw=socket_write(fd,"GET http://"+SITE+" HTTP/1.0\r\n"+
       "accept: www/source; text/html; image/gif; image/jpeg; */*\r\n"+
       "User_Agent: myAgent\r\n\r\n"
       ))!=EESUCCESS)
       {
               if(fail < 3)
               {
                fail++;
                remove_call_out("write_s");
                call_out("write_s",2,fd);
               }
               else
               {
                       fail=0;
                       close(fd);
               }
       }
       else
       {
               write("socket_write sucess!\n");
               fail=0;
}
}
