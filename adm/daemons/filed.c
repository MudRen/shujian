
#define DEBUGGER "no bady"
#define MAX_SIZE 1300

#define PORT_FILE 55443

#define DEBUG(y) do{ if (find_player(DEBUGGER)) tell_object(find_player(DEBUGGER),y+"\n"); }while (0)

#define JIAMI_C "/cmds/common/jiami.c"

#include <localtime.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <mudlib.h>

//inherit F_DBASE;

nosave string* listnens = ({
	"127.0.0.1",
	"202.100.222.243", //����
	"218.77.186.66",   //����
	"218.25.10.190",   //������
	"61.243.124.74",   //����
	"61.129.77.241",   //�Ϻ�(telcom)
	"221.11.134.1",	   //�Ϻ���(netcom)
	});
nosave string* sites = ({
	"CQ","LN","SH","SH2",
	});

nosave int Sock;
nosave int persistent;

nosave mapping sockets;
nosave mapping resolve_pending;

nosave string *months;

mapping files;
/*
([
		"/u/ciwei/man.c":([
				"wizard":"ciwei",
				"code":  "ϲ��",
				"flag":([
					"NIT":0,
				])
			])
		]);
*/
void set_persistent(int which);
void log_info(string msg);
protected void setup();
void store_client_info(int fd);
void close_connection(int fd);
void write_data(int fb,string str);
string get_file(string site);
string get_data(string name,int part);
int strtoint(string str);

public int add_file(string file,string id,string re)
{
	mapping flag=([]);
	mapping hehe=([]);
	for(int i=0;i<sizeof(sites);i++)
		flag[sites[i]] =0;
	hehe["wizard"] = id;
	hehe["code"] = re;
	hehe["flag"] = copy(flag);
	files[file] = copy(hehe);
}

string query(string arg)
{	
	if(arg=="channel_id") return "ͬ�����·���";
	return 0;
}

void create()
{ 
	seteuid( ROOT_UID );
	
	set_persistent(1);
	months = ({"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct",
		"Nov","Dec"});
	sockets = ([]);
	resolve_pending = ([]);
	files=([]);
	log_info("Created when uptime = " + uptime() + "\n");
	CHANNEL_D->do_channel(this_object(), "sys", "�����С���");
	if (member_array(INTERMUD_MUD_NAME, sites ) != -1)
		call_out("connect",10,"check");
	if (member_array(INTERMUD_MUD_NAME, sites ) == -1)
		call_out("setup", 2);
}

protected void setup()
{
	if ((Sock =
		socket_create(STREAM, "read_callback", "close_callback")) < 0)
	{
		log_info("setup: Failed to create socket.\n");
		return;
	}
	if (socket_bind(Sock, PORT_FILE) < 0) {
		socket_close(Sock);
		log_info("setup: Failed to bind socket to port.\n");
		return;
	}
	if (socket_listen(Sock, "listen_callback") < 0) {
		socket_close(Sock);
		log_info("setup: Failed to listen to socket.\n");
	}
	CHANNEL_D->do_channel(this_object(), "sys", "�����ɹ���");
	call_out("clear_file",60);
}

void clear_file()
{
	string* vb;
	int* flag;
	
	if(!files||files==([]))
	{
		call_out("clear_file",60);
		return;
	}
	vb = keys(files);
	for(int i=0;i<sizeof(vb);i++)
	{
		int* j;
		flag = values(files[vb[i]]["flag"]);
		j = unique_array(flag,(:$1==1:));
		if(sizeof(j)==sizeof(flag)) map_delete(files,vb[i]);
	}
	call_out("clear_file",60);
}

void read_callback(int fd, string str)
{
	string* quest;
	string file;
	string data;
	
	if(!str || !sizeof(str))
	{
		write_data(fd, "ERROR:Bad Request");
		return;
	}		
	DEBUG(sprintf("server read fd:%d,msg:%s  ",fd,str));
	
	quest = explode(str," ");
	
	if(!quest || !sizeof(quest))
	{
		write_data(fd, "ERROR:Bad Request");
		return;
	}
	
	switch(quest[0])
	{
		case "CHECK":
			if(undefinedp(quest[1]))
			{
				write_data(fd, "ERROR:Bad Request");
				return;
			}
			if(!(file=get_file(quest[1])))
			{
				write_data(fd,"EESUCCESS:nofile");//û����Ҫ���µ��ļ�
				return;
			}
			write_data(fd,sprintf("EESUCCESS:file:%s wizard:%s code:%s",file,files[file]["wizard"],files[file]["code"] ));
			return;
		case "GETFILE":
			if(undefinedp(quest[1])||undefinedp(quest[2])||undefinedp(quest[3]))
			{
				write_data(fd, "ERROR:Bad Request");
				return;
			}
			if(!(data = get_data(quest[2],strtoint(quest[3]))))
			{
				write_data(fd,sprintf("EESUCCESS:move%sdone",quest[2]));
				files[quest[2]]["flag"][quest[1]]=1;
				return;
			}
			write_data(fd,sprintf("EESUCCESS:name:%s part:%s code:%s",quest[2],quest[3],data));
			break;
		default:write_data(fd, "ERROR:Bad Request");
	}
}

int strtoint(string str)
{
	int re;
	if(!str) return 0;
	if(sscanf(str,"%d",re)==1) return re;
	return 0;
}

string get_data(string name,int part)
{
	string* parts;
	string data;
	
	data = read_file(name);	
	do
	{
		if(sizeof(data)<MAX_SIZE)
		{
			if(!parts) parts=({data});
			else parts += ({data});
			data = "";
		}
		else
		{
			if(!parts) parts=({data[0..MAX_SIZE-1]});
			else parts += ({data[0..MAX_SIZE-1]});
			data = data[MAX_SIZE..<0];
		}
	}
	while (data!="");
	if(part > sizeof(parts)) return 0;	
	return parts[part-1];
}

string get_file(string site)
{
	string* vb;
	int i;
	
	if(!files) return 0;
	vb = keys(files);
	if(!vb || !sizeof(vb)) return 0;
	for(i=0;i<sizeof(vb);i++)
	{
		if(undefinedp(files[vb[i]]["flag"][site])) continue;
		if(files[vb[i]]["flag"][site]==0) break;		
	}
	if(i==sizeof(vb)) return 0;
	return vb[i];
}

void write_data(int fb,string data)
{
	int rc;
	
	rc = socket_write(fb, data);	
	if (rc < 0) {
		log_info("setup: Failed to write to socket.\n");
	}
	DEBUG(sprintf("׼��write�� re:%d",rc));
	sockets[fb]["write_status"] = rc;
	close_connection(fb);
}

void close_connection(int fd)
{
	if (sockets[fd]["write_status"] == EECALLBACK) {
		return;
	}
	map_delete(sockets, fd);
	map_delete(resolve_pending, fd);
	socket_close(fd);
}

void listen_callback(int fd)
{
	int nfd;
	
	DEBUG(sprintf("server linter fd:%d    ",fd));
	
	if ((nfd = socket_accept(fd, "read_callback", "write_callback")) < 0) {
		log_info("listen_callback: socket_accept failed.\n");
		return;
	}
	store_client_info(nfd);
}

void close_callback(int fd)
{
	DEBUG(sprintf("server close fd:%d    ",fd));
	if (fd == Sock) {
		log_info("HTTP socket closed unexpectedly; restarting.\n");
		call_out("setup", 5);
	} else {
		if (undefinedp(sockets[fd])) {
			log_info(sprintf("Client socket %d closed unexpectedly\n", fd));
		} else {
			log_info(sprintf("Client socket %s %d closed unexpectedly.\n",
			sockets[fd]["name"], sockets[fd]["port"]));
		}
		map_delete(sockets, fd);
	}
}

void store_client_info(int fd)
{
	string addr;
	int port;
	
	DEBUG(sprintf("server linter over fd:%d    ",fd));

	sscanf(socket_address(fd), "%s %d", addr, port);
	DEBUG(sprintf("server get slins msg add:%s,prot:%d",addr,port));
	if(member_array(addr,listnens)==-1){
		log_info(sprintf("attpemt to connect,add:%s",addr));
		socket_close(fd);
		return;
	}
	sockets[fd] = ([
	 "address" : addr,
	 "name" : addr,
	 "port" : port,
	 "time" : time(),
	 "write_status" : EESUCCESS
	]);
}

void log_info(string msg)
{
	log_file("nosave/super_ftp",msg);
}

void set_persistent(int which)
{
   persistent = which;
}
///////////////////////////////////slient//////////////////////////////

#define UNIQUE_SERVER_ADDR	"61.243.124.74 "+PORT_FILE

nosave string file_data;
nosave string file_name;
nosave string code_wizard;
nosave string code_code;
nosave int file_part;

int connect(string writetype)
{
	int fd,result;
	
	remove_call_out("connect");
	fd = socket_create(STREAM,"read_callback1","close_callback1");
	if (fd<0) {
		log_info(sprintf("error   :%15s:%5d:\n","socket_create",fd));
		return 0;
	}
	result= socket_connect(fd,UNIQUE_SERVER_ADDR,"read_callback2",writetype);
	call_out("failed",60,fd);
	if ( result != EESUCCESS) {
		log_info(sprintf("error   :%15s:%5d:\n","socket_connect",result));
		return 0;
	}
	return 1;
}
void failed(int fd)
{
	socket_close(fd);
	remove_call_out("connect");
	call_out("connect",10,"check");
}
void read_callback1(int fd, mixed message){}

void close_callback1(int fd){}

void read_callback2(int fd, string str)
{
	string data;
	
	remove_call_out("failed");
	remove_call_out("connect");
	DEBUG(sprintf("slient read back fd:%d,msg:%s",fd,str));
	if(sscanf(str,"ERROR:%s",str)==1)
	{
		log_info("socket error be "+str);
		call_out("connect",10,"check");
		return;
	}
	else if(sscanf(str,"EESUCCESS:%s",str)==1)
	{
		if(str=="nofile")
		{
			call_out("connect",10,"check");
			return;
		}
		else if(sscanf(str,"file:%s wizard:%s code:%s",file_name,code_wizard,code_code)==3)
		{
			file_data="";
			file_part=1;
			CHANNEL_D->do_channel(this_object(),"sys","׼������"+file_name+"��");
			call_out("connect",0,"getfile");
			return;
		}
		else if(sscanf(str,"move%sdone",str)==1)
		{
			write_file(file_name,file_data,1);
			//jiami
			JIAMI_C->main(this_object(),file_name);
			//log
			CHANNEL_D->do_channel(this_object(),"sys","����"+file_name+"��ɣ������߹�����Ա�������Ӧ�ó���");
			log_file("nosave/super_ftp",sprintf("����%-30s,%-8s����%s",code_code,code_wizard,file_name),this_object());
			call_out("connect",1,"check");
			return;
		}
		else if(sscanf(str,"name:%*s part:%*s code:%s",data)==3)
		{
			file_part++;
			file_data += data;
			CHANNEL_D->do_channel(this_object(),"sys","��������"+file_name+"��");
			call_out("connect",0,"getfile");
			return;
		}
	}
}

void check(int fd)
{
	string str;
	int result;
	
	remove_call_out("failed");
	remove_call_out("connect");
	call_out("failed",60,fd);
	
	str = sprintf("CHECK %s",INTERMUD_MUD_NAME);
	DEBUG(sprintf("slient write(%d): %s\n",fd,str));
	result = socket_write(fd,str);
	if ( result != EESUCCESS ) {
		log_info(sprintf("failed"));
		return;
	}
}

void getfile(int fd)
{
	string str;
	int result;
	
	remove_call_out("failed");
	remove_call_out("connect");
	call_out("failed",60,fd);
		
	str = sprintf("GETFILE %s %s %d",INTERMUD_MUD_NAME,file_name,file_part);
	DEBUG(sprintf("slient write(%d): %s\n",fd,str));
	result = socket_write(fd,str);
	if ( result != EESUCCESS ) {
		log_info(sprintf("failed"));
		return;
	}
}
